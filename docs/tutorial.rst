Tutorial (basics)
=================
.. highlight:: c++

This short example shows how to set up a basic experiment to optimize
parameters using a user-defined fitness.

Running a sferes2 executable
----------------------------

Waf put all the compiled files in the "build" directory. Two variants
are produced: "default" and "debug". You should always run the debug
version first because the default version disables assert. Each variant
mirrors the architecture of the main sferes2 directory.

Sferes2 contains some basic examples in the "examples" directory. For
instance, let's check "ex_ea.cpp", a basic single-objective
optimization of parameters. To launch the debug version, you should run:

.. code:: shell

    build/debug/examples/ex_ea

A verbose mode is also available:

.. code:: shell

    build/debug/examples/ex_ea -v all

And a more verbose one:

.. code:: shell

    build/debug/examples/ex_ea -v all -v trace

For the optimized version:

.. code:: shell

    build/default/examples/ex_ea

Running one of those commands should create a directory named using the
schema binary_name_year-month-day_hours_min_seconds_PID (this is designed to be a unique name to avoid overwriting any previous result). In this directory there are:

-  a file called "bestfit.dat", which contains, for each generation, the
   value of the best fitness;
-  many files calles `gen_xxx` where xxx is a generation number.

These files are boost::serialization binary files (optionnaly XML files, if needed) that typically store the best candidates solutions for each generation (xxx is the generation number). It actually saves all the `statistics` instances (e.g., `BestFit`, `ParetoFront`, etc.).


Loading a result file
---------------------

These binary files are designed to be read by the same executable which generated the result files:

.. code:: shell

    ../build/default/examples/ex_ea --load gen_1000 -o output_file -n number

-  `output_file` is a text file which, most of the time (depending
   on the genotype and phenotype used), describes the best individual
   (or the Pareto-optimal set in multiobjective optimization); in this
   example, it contains the value of the parameters for the best
   individual:

.. code:: shell

    cat output_file
    8.46386e-05 -4.58956e-05 -4.88758e-05 -6.02007e-05 3.93391e-05 -0.000165701 5.96046e-06 0.00010848 0.000445843 -0.000101328 

- `number` is the number of the individual described in the statistics you want to load.

- optionnally, the option `-s` allows to specify the statistics number (e.g, if you have `BestFit<>` and `ParetoFront<>` in your statistics list, then `BestFit<>` is `0` and `ParetoFront<>` is number `1`.

Building your own experiment
----------------------------

Setting everything up
~~~~~~~~~~~~~~~~~~~~~

#. Create directories and files

   -  At the root of the sferes repository (the main directory), use waf
      to create a new experiment. Let's call it "test":

   .. code:: shell

       ./waf --create test

   This should have created a new directory exp/test, a waf file
   exp/test/wscript and a basic file exp/test/test.cpp. You can now
   edit/customize them.

#. Compiling

   -  In the main sferes2 directory (not in the experiment's directory):

   .. code:: shell

       ./waf --exp my_exp

   If the experiment is called "test", the command line is:

   .. code:: shell

       ./waf --exp test

#. Running

   .. code:: shell

       cd exp/test
       ../../build/debug/exp/test/test

   and for the optimized version:

   .. code:: shell

       ../../build/default/exp/test/test

Customizing / writing the experiment
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Let's start with exp/test/test.cpp, *from the end of the file*.

Main function
^^^^^^^^^^^^^^ 

   At the end of the file, you should see a main() function. It defines
   some types using typedef then run the evolutionary algorithm. The
   types describe our experiment (what kind of genotype? what kind of
   fitness? what kind of algorithm?). We will go back to the Params
   class in the following section. Ignore it for now.

.. code:: c++

       int main(int argc, char **argv)
       {
         // Our fitness is the class FitTest (see above), that we call
         // fit_t. Params is the set of parameters (struct Params) defined in
         // this file.
         typedef FitTest<Params> fit_t;
         // We define the genotype. Here we choose EvoFloat (real
         // numbers). We evolve 10 real numbers, with the params defined in
         // Params (cf the beginning of this file)
         typedef gen::EvoFloat<10, Params> gen_t;
         // This genotype should be simply transformed into a vector of
         // parameters (phen::Parameters). The genotype could also have been
         // transformed into a shape, a neural network... The phenotype need
         // to know which fitness to use; we pass fit_t to it.
         typedef phen::Parameters<gen_t, fit_t, Params> phen_t;
         // The evaluator is in charge of distributing the evaluation of the
         // population. It can be simple eval::Eval (nothing special),
         // parallel (for multicore machines, eval::Parallel) or distributed
         // (for clusters, eval::Mpi).
         typedef eval::Eval<Params> eval_t;
         // Statistics gather data about the evolutionary process (mean
         // fitness, Pareto front, ...). Since they can also store the best
         // individuals, they are the container of our results. We can add as
         // many statistics as required thanks to the boost::fusion::vector.
         typedef boost::fusion::vector<stat::BestFit<phen_t, Params>, stat::MeanFit<Params> >  stat_t;
         // Modifiers are functors which are run once all individuals have
         // been evalutated. Their typical use is to add some evolutionary
         // pressures towards diversity (e.g. fitness sharing). Here we don't
         // use this feature. As a consequence we use a "dummy" modifier that
         // does nothing.
         typedef modif::Dummy<> modifier_t;
         // We can finally put everything together. RankSimple is the
         // evolutionary algorithm. It is parametrized by the phenotype, the
         // evaluator, the statistics list, the modifier and the general params.
         typedef ea::RankSimple<phen_t, eval_t, stat_t, modifier_t, Params> ea_t;
         // We now have a special class for our experiment: ea_t. The next
         // line instantiates an object of this class
         ea_t ea;
         // We can now process the command line options and run the
         // evolutionary algorithm (if a --load argument is passed, the file
         // is loaded; otherwise, the algorithm is launched).
         run_ea(argc, argv, ea);
         //
         return 0;
       }

Include part
^^^^^^^^^^^^

   Let's now go back to the top of the file. The file starts with the
   usual include files, which obviously depends on which classes
   (genotype, phenotype, ea, …) you selected in the main function:

.. code:: c++

       #include <iostream>
       #include <sferes/phen/parameters.hpp>
       #include <sferes/gen/evo_float.hpp>
       #include <sferes/ea/rank_simple.hpp>
       #include <sferes/eval/eval.hpp>
       #include <sferes/stat/best_fit.hpp>
       #include <sferes/stat/mean_fit.hpp>
       #include <sferes/modif/dummy.hpp>
       #include <sferes/run.hpp>

Params
^^^^^^

   Then, the Params structure defines the parameters of the algorithm.
   This particular way of setting them allows the compiler to propagate
   constants to the whole programm (i.e. it replaces the parameters in
   the code by their values), allowing some optimizations. This
   parameters will depend on the algorithms you chose to use in your
   main function.

.. code:: c++

       struct Params
       {
         struct evo_float
         {
           // we choose the polynomial mutation type
           SFERES_CONST mutation_t mutation_type = polynomial;
           // we choose the polynomial cross-over type
           SFERES_CONST cross_over_t cross_over_type = sbx;
           // the mutation rate of the real-valued vector
           SFERES_CONST float mutation_rate = 0.1f;
           // a parameter of the polynomial mutation
           SFERES_CONST float eta_m = 15.0f;
           // a parameter of the polynomial cross-over
           SFERES_CONST float eta_c = 10.0f;
         };
         struct pop
         {
           // size of the population
           SFERES_CONST unsigned size = 200;
           // number of generations
           SFERES_CONST unsigned nb_gen = 2000;
           // how often should the result file be written (here, each 5
           // generation)
           SFERES_CONST int dump_period = 5;
           // how many individuals should be created during the random
           // generation process?
           SFERES_CONST int initial_aleat = 1;
           // used by RankSimple to select the pressure
           SFERES_CONST float coeff = 1.1f;
           // the number of individuals which are kept from one generation to
           // another (elitism)
           SFERES_CONST float keep_rate = 0.6f;    
         };
         struct parameters
         {
           // maximum value of the phenotype parameters
           SFERES_CONST float min = -10.0f;
           // minimum value
           SFERES_CONST float max = 10.0f;
         };
       };

Fitness function
^^^^^^^^^^^^^^^^

   Last, it's time to write the fitness function. It's a special class
   with an "eval()" function which derives from fit::Fitness. It has to
   fill `this->_value` in single-objective optimization and
   this->_objs` in multiobjective optimization. In this example,
   we want to maximize :math:`-\sum_i p_i^4`, where :math:`p` is the
   individual's phenotype.

.. code:: c++

       SFERES_FITNESS(FitTest, sferes::fit::Fitness)
       {
        public:
         // indiv will have the type defined in the main (phen_t)
         template<typename Indiv>
           void eval(const Indiv& ind) 
         {
           float v = 0;
           for (unsigned i = 0; i < ind.size(); ++i)
             {
              float p = ind.data(i);
              v += p * p * p * p;
             }
           this->_value = -v;
         }
       };

It can also be useful to print a few things (debug, result, 3D graphics, additionnal information, etc.) **when we are in loading mode**. 
This is easily achieved like this:


.. code:: c++

       SFERES_FITNESS(FitTest, sferes::fit::Fitness)
       {
        public:
         // indiv will have the type defined in the main (phen_t)
         template<typename Indiv>
           void eval(const Indiv& ind) 
         {
           float v = 0;
           for (unsigned i = 0; i < ind.size(); ++i)
             {
              float p = ind.data(i);
              v += p * p * p * p;
             }
           this->_value = -v;
           // code specific to loading mode
           if (this->mode() == sferes::fit::view) {
              std::cout << "Value:" << this->_value << std::endl;
           }
         }
       };

You can now have a look at the `examples` directory.
