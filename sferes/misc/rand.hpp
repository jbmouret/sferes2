//| This file is a part of the sferes2 framework.
//| Copyright 2009, ISIR / Universite Pierre et Marie Curie (UPMC)
//| Main contributor(s): Jean-Baptiste Mouret, mouret@isir.fr
//|
//| This software is a computer program whose purpose is to facilitate
//| experiments in evolutionary computation and evolutionary robotics.
//|
//| This software is governed by the CeCILL license under French law
//| and abiding by the rules of distribution of free software.  You
//| can use, modify and/ or redistribute the software under the terms
//| of the CeCILL license as circulated by CEA, CNRS and INRIA at the
//| following URL "http://www.cecill.info".
//|
//| As a counterpart to the access to the source code and rights to
//| copy, modify and redistribute granted by the license, users are
//| provided only with a limited warranty and the software's author,
//| the holder of the economic rights, and the successive licensors
//| have only limited liability.
//|
//| In this respect, the user's attention is drawn to the risks
//| associated with loading, using, modifying and/or developing or
//| reproducing the software by the user in light of its specific
//| status of free software, that may mean that it is complicated to
//| manipulate, and that also therefore means that it is reserved for
//| developers and experienced professionals having in-depth computer
//| knowledge. Users are therefore encouraged to load and test the
//| software's suitability as regards their requirements in conditions
//| enabling the security of their systems and/or data to be ensured
//| and, more generally, to use and operate it in the same conditions
//| as regards security.
//|
//| The fact that you are presently reading this means that you have
//| had knowledge of the CeCILL license and that you accept its terms.

#ifndef RAND_HPP_
#define RAND_HPP_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <random>
#include <stdlib.h>

// a few external tools for seeding (GPL-licensed)
#include "sferes/misc/rand_utils.hpp"

namespace sferes {
    namespace misc {
        /// usage :
        /// - RandomGenerator<dist<double>>(0.0, 1.0);
        /// - double r = rgen.rand();
        template <typename D>
        class RandomGenerator {
        public:
            using result_type = typename D::result_type;
            RandomGenerator(result_type a, result_type b) : _dist(a, b), _rgen(randutils::auto_seed_128{}.base()) {}
            result_type rand()
            {
                return _dist(_rgen);
            }
            D& dist() { return dist; }

        private:
            D _dist;
            std::mt19937 _rgen;
        };

        // thread-safe
        template <typename T>
        inline T rand(T min, T max)
        {
            using rgen_t = RandomGenerator<std::uniform_real_distribution<T>>;
            assert(max > min);
            static thread_local T _min = min;
            static thread_local T _max = max;
            static thread_local rgen_t rgen(min, max);
            if (max != _max || min != _min) {
                std::cout<<"change max-min"<<std::endl;
                _max = max;
                _min = min;
                rgen = rgen_t(_min, _max);
            }
            T v = rgen.rand();
            assert(v >= min);
            assert(v < max);
            return v;
        }

        template<>
        inline int rand<int>(int min, int max)
        {
            using rgen_t = RandomGenerator<std::uniform_int_distribution<int>>;
            assert(max > min);
            static thread_local int _min = min;
            static thread_local int _max = max;
            static thread_local rgen_t rgen(min, max);
            if (max != _max || min != _min) {
                std::cout<<"change max-min int"<<std::endl;
                _max = max;
                _min = min;
                rgen = rgen_t(_min, _max);
            }
            int v = rgen.rand();
            assert(v >= min);
            assert(v < max);
            return v;
        }

        template <typename T>
        inline T rand(T max = 1.0)
        {
            return rand<T>((T)0.0, max);
        }

        template <typename T>
        inline T gaussian_rand(T m = 0.0, T v = 1.0)
        {
            using rgen_t = RandomGenerator<std::normal_distribution<T>>;
            static thread_local rgen_t rgen(m, v);
            static thread_local T _m = m;
            static thread_local T _v = v;
            if (v != v || _m != m) {
                _m = m;
                _v = v;
                rgen = rgen_t(m, v);
            }
            T val = rgen.rand();
            return val;
        }

        // randomize indices
        inline void rand_ind(std::vector<size_t>& a1, size_t size)
        {
            a1.resize(size);
            for (size_t i = 0; i < a1.size(); ++i)
                a1[i] = i;
            for (size_t i = 0; i < a1.size(); ++i) {
                size_t k = rand(i, a1.size());
                assert(k < a1.size());
                std::swap(a1[i], a1[k]);
            }
        }

        /// return a random it in the list
        template <typename T>
        inline typename std::list<T>::iterator rand_in_list(std::list<T>& l)
        {
            using rgen_t = RandomGenerator<std::uniform_int_distribution<int>>;
            static thread_local rgen_t rgen(0, l.size());
            int n = rgen.rand();
            typename std::list<T>::iterator it = l.begin();
            for (int i = 0; i < n; ++i)
                ++it;
            return it;
        }

        inline bool flip_coin()
        {
            return rand<float>() < 0.5f;
        }

        template <typename L>
        inline typename L::iterator rand_l(L& l)
        {
            using rgen_t = RandomGenerator<std::uniform_int_distribution<int>>;
            static thread_local rgen_t rgen(0, l.size());
            int k = rgen.rand();
            typename L::iterator it = l.begin();
            for (size_t i = 0; i < k; ++i)
                ++it;
            return it;
        }
    } // namespace misc
} // namespace sferes
#endif
