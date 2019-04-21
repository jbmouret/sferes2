sferes2 [![Build Status](https://img.shields.io/travis/sferes2/sferes2.svg)](https://travis-ci.org/sferes2/sferes2)
=======

Sferes2 is a high-performance, multi-core, lightweight, generic C++98 framework for evolutionary computation. It is mainly used in our research about:
- neuro-evolution
- quality diversity
- behavioral diversity
- multi-objectivization

It is intently kept small to stay reliable and understandable.

Sferes2 heavily relies on template-based meta-programming in C++ to get both abstraction and execution speed.

**If you use this software in an academic article, please cite:**

Mouret, J.-B. and Doncieux, S. (2010). SFERESv2: Evolvin' in the Multi-Core World. _Proc. of Congress on Evolutionary Computation (CEC)_ Pages 4079--4086.

The article is available here: http://www.isir.upmc.fr/files/2010ACTI1524.pdf

```
@INPROCEEDINGS{Mouret2010,
	AUTHOR = {Mouret, J.-B. and Doncieux, S.},
	TITLE = {{SFERES}v2: Evolvin' in the Multi-Core World},
	YEAR = {2010},
	BOOKTITLE = {Proc. of Congress on Evolutionary Computation (CEC)},
	PAGES = {4079--4086}
}
```

Documentation (including instruction for compilation)
-------------

We are in the process of porting the documentation to a sphinx website (read-the-doc). Current documentation: https://github.com/jbmouret/sferes2/wiki

**Warning** Sferes2 now requires a C++11 compiler (recent versions of g++ or clang++ work fine).

Optional modules
---------------
- evolvable neural networks: https://github.com/jbmouret/nn2
- khepera-like simulator: https://github.com/jbmouret/fastsim


Design
-----
The following choices were made in the initial design:
- use of modern c++ techniques (template-based programming) to employ object-oriented programming without the cost of virtual functions;
- use of Intel TBB to take full advantages of multicore and SMP systems;
- use of boost libraries when it's useful (shared_ptr, serialization, filesystem, test,...);
- use of MPI to distribute the computational cost on clusters;
- a full set of unit tests;
- no configuration file: a fully optimized executable is built for each particular experiment.

Sferes2 is extended via modules and experiments.

Sferes2 should work on most Unix systems (in particular, GNU/Linux and OSX). It successfully compiles with gcc, clang and icc (if it is not the case, please file a bug report in the issue tracker).


Author
-------
- Jean-Baptiste Mouret - jean-baptiste.mouret@inria.fr: main author and maintainer

Other contributors
------------
- Antoine Cully (QD module) - antoine.cully@imperial.edu
- Stephane Doncieux - doncieux@sorbonne-universite.fr
- Konstantinos Chatzilygeroudis - konstantinos.chatzilygeroudis@inria.fr
- Paul Tonelli - tonelli@isir.upmc.fr (documentation)
- Many members of ISIR (http://isir.upmc.fr)

Peer-reviewed academic papers that used Sferes2:
------------------------------------------------
*If you used Sferes2 in an academic paper, please send us an e-mail (jean-baptiste.mouret@inria.fr) so that we can add it here!*

(you can find a pdf for most of these publications on http://scholar.google.com).

### 2018
- Cully et al. TODO
- Vassiliades and Mouret TODO
- AAAI paper TODO

### 2017
- Pautrat et al. TODO
- Maurice, P., Padois, V., Measson, Y., & Bidaud, P. (2017). Human-oriented design of collaborative robots. International Journal of Industrial Ergonomics, 57, 88-102.
- Viejo, G., Girard, B., Procyk, E., & Khamassi, M. (2017). Adaptive coordination of working-memory and reinforcement learning in non-human primates performing a trial-and-error problem solving task. Behavioural Brain Research.
- Vassiliades, V., Chatzilygeroudis, K., & Mouret, J. B. (2017). Using centroidal voronoi tessellations to scale up the multi-dimensional archive of phenotypic elites algorithm. IEEE Transactions on Evolutionary Computation.

### 2016
- Mengistu, H., Huizinga, J., Mouret, J.-B., & Clune, J. The evolutionary origins of hierarchy. PLoS Computational Biology, Public Library of Science, 2016, 12 (6),
- Velez, R., and Clune, J.. "Identifying Core Functional Networks and Functional Modules within Artificial Neural Networks via Subsets Regression." Proceedings of the Genetic and Evolutionary Computation Conference. 2016.
- Tarapore, D. Clune, J., Cully, A., and Mouret, J.-B "How Do Different Encodings Influence the Performance of the MAP-Elites Algorithm?" Proceedings of the Genetic and Evolutionary Computation Conference. 2016.
-  Huizinga J., Mouret J.-B., Clune J. "Does aligning phenotypic and genotypic modularity improve the evolution of neural networks?" Proceedings of the Genetic and Evolutionary Computation Conference. 2016.
- Norouzzadeh M., Clune J. Neuromodulation improves the evolution of forward models. Proceedings of the Genetic and Evolutionary Computation Conference. 2016.
- Stanton, C., and Clune J. "Curiosity Search: Producing Generalists by Encouraging Individuals to Continually Explore and Acquire Skills throughout Their Lifetime." PloS one 11.9 (2016): e0162235.
- Nguyen A, Yosinski J, Clune J. Understanding Innovation Engines: Automated Creativity and Improved Stochastic Optimization via Deep Learning. Evolutionary Computation. 2016 Sep;24(3):545-72.
- Bernard, A., André, J. B., & Bredeche, N. (2016). Evolving specialisation in a population of heterogeneous robots: the challenge of bootstrapping and maintaining genotypic polymorphism. Artificial Life, 15, 1-8.
- Pontes, J., Doncieux, S., Santos, C., & Padois, V. (2016). An Adaptive Approach to Humanoid Locomotion. In Advances in Cooperative Robotics--Proceedings of the 19th International Conference on Climbing and Walking Robots and the Support Technologies for Mobile Machines (pp. 437-444).

### 2015
- Maestre, Carlos, Antoine Cully, Christophe Gonzales, and Stephane Doncieux. "Bootstrapping interactions with objects from raw sensorimotor data: a Novelty Search based approach." In IEEE International Conference on Developmental and Learning and on Epigenetic Robotics. 2015.
- Cully, Antoine, Jeff Clune, Danesh Tarapore, and Jean-Baptiste Mouret. "Robots that can adapt like animals." Nature 521, no. 7553 (2015): 503-507.
- Viejo, Guillaume, Mehdi Khamassi, Andrea Brovelli, and Benoît Girard. "Modeling choice and reaction time during arbitrary visuomotor learning through the coordination of adaptive working memory and reinforcement learning." Frontiers in behavioral neuroscience 9 (2015).
- Nguyen, Anh, Jason Yosinski, and Jeff Clune. "Innovation engines: Automated creativity and improved stochastic optimization via deep learning." In Proceedings of the Genetic and Evolutionary Computation Conference. 2015.
- Maestre, Carlos, Antoine Cully, Christophe Gonzales, and Stephane Doncieux. "Bootstrapping interactions with objects from raw sensorimotor data: a Novelty Search based approach." In IEEE International Conference on Developmental and Learning and on Epigenetic Robotics. 2015.
- Shrouf, Fadi, Joaquin Ordieres-Meré, Alvaro García-Sánchez, and Miguel Ortega-Mier. "Optimizing the production scheduling of a single machine to minimize total energy consumption costs." Journal of Cleaner Production 67 (2014): 197-207.
- Ellefsen, Kai Olav, Jean-Baptiste Mouret, and Jeff Clune. "Neural Modularity Helps Organisms Evolve to Learn New Skills without Forgetting Old Skills." PLoS Comput Biol 11.4 (2015): e1004128.
- Cully, Antoine, and J-B. Mouret. "Evolving a Behavioral Repertoire for a Walking Robot." Evolutionary computation (2015).
- Mouret, Jean-Baptiste, and Jeff Clune. "Illuminating search spaces by mapping elites." arXiv preprint arXiv:1504.04909 (2015).
- Tarapore, Danesh, and Jean-Baptiste Mouret. "Evolvability signatures of generative encodings: beyond standard performance benchmarks." Information Sciences (2015).
- Nguyen, A., Yosinski, J. and Clune, J.. "Deep neural networks are easily fooled: High confidence predictions for unrecognizable images." Computer Vision and Pattern Recognition (CVPR), 2015 IEEE Conference on. IEEE, 2015.
- Bernard, A., André, J.B. and Bredeche, N., 2015. Evolution of Cooperation in Evolutionary Robotics: the Tradeoff between Evolvability and Efficiency. In Proceedings of the European Conference on Artificial Life 2015 (pp. 195-502).
 
### 2014
-  Doncieux, S. (2014). Knowledge Extraction from Learning Traces in Continuous Domains. AAAI 2014 fall Symposium ''Knowledge, Skill, and Behavior Transfer in Autonomous Robots''. Pages 1-8.

- Lesaint, F., Sigaud, O., Clark, J. J., Flagel, S. B., & Khamassi, M. (2014). Experimental predictions drawn from a computational model of sign-trackers and goal-trackers. Journal of Physiology-Paris.
- Lesaint, F., Sigaud, O., Flagel, S. B., Robinson, T. E., & Khamassi, M. (2014). Modelling Individual Differences in the Form of Pavlovian Conditioned Approach Responses: A Dual Learning Systems Approach with Factored Representations. PLoS computational biology, 10(2), e1003466.
- Shrouf, F., Ordieres-Meré, J., García-Sánchez, A., & Ortega-Mier, M. (2014). Optimizing the production scheduling of a single machine to minimize total energy consumption costs. Journal of Cleaner Production, 67, 197-207.
- Huizinga, J., Mouret, J. B., & Clune, J. (2014). Evolving Neural Networks That Are Both Modular and Regular: HyperNeat Plus the Connection Cost Technique. In Proceedings of GECCO (pp. 1-8).
- Li, J., Storie, J., & Clune, J. (2014). Encouraging Creative Thinking in Robots Improves Their Ability to Solve Challenging Problems. Proceedings of GECCO (pp 1-8)
- Tarapore, D. and Mouret, J.-B. (2014). Comparing the evolvability of generative encoding schemes.
Artificial Life 14: Proceedings of the Fourteenth International Conference on the Synthesis and Simulation of Living Systems, MIT Press, publisher. Pages 1-8.


### 2013
- Koos, S. and Cully, A. and Mouret, J.-B. (2013). Fast Damage Recovery in Robotics with the T-Resilience Algorithm. International Journal of Robotics Research. Vol 32 No 14 Pages 1700-1723.
- Tonelli, P. and Mouret, J.-B. (2013). On the Relationships between Generative Encodings, Regularity, and Learning Abilities when Evolving Plastic Artificial Neural Networks. PLoS One. Vol 8 No 11 Pages e79138
- Clune*, J. and Mouret, J.-B. and Lipson, H. (2013). The evolutionary origins of modularity. Proceedings of the Royal Society B. Vol 280 (J. Clune and J.-B. Mouret contributed equally to this work) Pages 20122863
- Koos, S. and Mouret, J.-B. and Doncieux, S. (2013). The Transferability Approach: Crossing the Reality Gap in Evolutionary Robotics. IEEE Transactions on Evolutionary Computation. Vol 17 No 1 Pages 122 - 145 
- Doncieux, S. and Mouret, J.B. (2013). Behavioral Diversity with Multiple Behavioral Distances. Proc. of IEEE Congress on Evolutionary Computation, 2013 (CEC 2013). Pages 1-8
- Cully, A. and Mouret, J.-B. (2013). Behavioral Repertoire Learning in Robotics. Genetic and Evolutionary Computation Conference (GECCO). Pages 175-182.
- Doncieux, S. (2013). Transfer Learning for Direct Policy Search: A Reward Shaping Approach. Proceedings of ICDL-EpiRob conference. Pages 1-6.

### 2012
- Mouret, J.-B. and Doncieux, S. (2012). Encouraging Behavioral Diversity in Evolutionary Robotics: an Empirical Study. Evolutionary Computation. Vol 20 No 1 Pages 91-133.
- Ollion, Charles and Doncieux, Stéphane (2012). Towards Behavioral Consistency in Neuroevolution. From Animals to Animats: Proceedings of the 12th International Conference on Adaptive Behaviour (SAB 2012), Springer, publisher. Pages 1-10.
- Ollion, C. and Pinville, T. and Doncieux, S. (2012). With a little help from selection pressures: evolution of memory in robot controllers. Proc. Alife XIII. Pages 1-8.

### 2011
- Rubrecht, S. and Singla, E. and Padois, V. and Bidaud, P. and de Broissia, M. (2011). Evolutionary design of a robotic manipulator for a highly constrained environment. Studies in Computational Intelligence, New Horizons in Evolutionary Robotics, Springer, publisher. Vol 341 Pages 109-121.
-  Doncieux, S. and Hamdaoui, M. (2011). Evolutionary Algorithms to Analyse and Design a Controller for a Flapping Wings Aircraft. New Horizons in Evolutionary Robotics Extended Contributions from the 2009 EvoDeRob Workshop, Springer, publisher. Pages 67--83.
-  Mouret, J.-B. (2011). Novelty-based Multiobjectivization. New Horizons in Evolutionary Robotics: Extended Contributions from the 2009 EvoDeRob Workshop, Springer, publisher. Pages 139--154.
-  Pinville, T. and Koos, S. and Mouret, J-B. and Doncieux, S. (2011). How to Promote Generalisation in Evolutionary Robotics: the ProGAb Approach. GECCO'11: Proceedings of the 13th annual conference on Genetic and evolutionary computation ACM, publisher . Pages 259--266.
-  Koos, S. and Mouret, J-B. (2011). Online Discovery of Locomotion Modes for Wheel-Legged Hybrid Robots: a Transferability-based Approach. Proceedings of CLAWAR, World Scientific Publishing Co., publisher. Pages 70-77.
- Tonelli, P. and Mouret, J.-B. (2011). On the Relationships between Synaptic Plasticity and Generative Systems. Proceedings of the 13th Annual Conference on Genetic and Evolutionary Computation. Pages 1531--1538. (Best paper of the Generative and Developmental Systems (GDS) track).
-  Terekhov, A.V. and Mouret, J.-B. and Grand, C. (2011). Stochastic optimization of a chain sliding mode controller for the mobile robot maneuvering. Proceedings of IEEE / IROS Int. Conf. on Robots and Intelligents Systems. Pages 4360 - 4365

### 2010
- Mouret, J.-B. and Doncieux, S. and Girard, B. (2010). Importing the Computational Neuroscience Toolbox into Neuro-Evolution---Application to Basal Ganglia. GECCO'10: Proceedings of the 12th annual conference on Genetic and evolutionary computation ACM, publisher . Pages 587--594.
- Koos, S. and Mouret, J.-B. and Doncieux, S. (2010). Crossing the Reality Gap in Evolutionary Robotics by Promoting Transferable Controllers. GECCO'10: Proceedings of the 12th annual conference on Genetic and evolutionary computation ACM, publisher . Pages 119--126.
- Doncieux, S. and Mouret, J.-B. (2010). Behavioral diversity measures for Evolutionary Robotics. WCCI 2010 IEEE World Congress on Computational Intelligence, Congress on Evolutionary Computation (CEC). Pages 1303--1310.
- Terekhov, A.V. and Mouret, J.-B. and Grand, C. (2010). Stochastic optimization of a neural network-based controller for aggressive maneuvers on loose surfaces. Proceedings of IEEE / IROS Int. Conf. on Robots and Intelligents Systems. Pages 4782 - 4787
- Terekhov, A.V and Mouret, J.-B. and Grand, C (2010). Stochastic multi-objective optimization for aggressive maneuver trajectory planning on loose surface.
Proceedings of IFAC: the 7th Symposium on Intelligent Autonomous Vehicles. Pages 1-6 
-  Liénard, J. and Guillot, A. and Girard, B. (2010). Multi-Objective Evolutionary Algorithms to Investigate Neurocomputational Issues : The Case Study of Basal Ganglia Models. From animals to animats 11, Springer, publisher. Vol 6226 Pages 597--606

### 2009
- Koos, S. and Mouret, J.-B. and Doncieux, S. (2009). Automatic system identification based on coevolution of models and tests. IEEE Congress on Evolutionary Computation, 2009 (CEC 2009). Pages 560--567
-  Mouret, J.-B. and Doncieux, S. (2009). Evolving modular neural-networks through exaptation. IEEE Congress on Evolutionary Computation, 2009 (CEC 2009). Pages 1570--1577. (Best student paper award)
-  Mouret, J.-B. and Doncieux, S. (2009). Overcoming the bootstrap problem in evolutionary robotics using behavioral diversity. IEEE Congress on Evolutionary Computation, 2009 (CEC 2009). Pages 1161 - 1168
-  Mouret, J.-B. and Doncieux, S. (2009). Using Behavioral Exploration Objectives to Solve Deceptive Problems in Neuro-evolution. GECCO'09: Proceedings of the 11th annual conference on Genetic and evolutionary computation , ACM, publisher. Pages 627--634.
