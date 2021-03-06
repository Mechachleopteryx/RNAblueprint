/*!\file parsestruct.h 
 * \brief This file holds the functions to parse a dot-bracket representation to a boost graph and set the sequence constraints.
 *
 * @date 25.03.2013
 * @author Stefan Hammer <s.hammer@univie.ac.at>
 * @copyright GPLv3
 *
 * \cond INTERNAL
 */

#ifndef PARSESTRUCT_H
#define PARSESTRUCT_H

// include common header with graph definition and global variables
#include "common.h"
#include "graphcommon.h"

// include standard library parts
#include <sstream>
#include <cctype>
#include <iterator>
#include <cstddef>
#include <unordered_map>

namespace design {
    namespace detail {
        
        typedef std::vector< std::pair<char, char> > BracketList;
        
        // parse the input string into a graph
        Graph parse_structures(std::vector<std::string> structures);
        // recursion for different brackets
        void parse_bracket(Graph& g, std::string& structure, BracketList::iterator bracket);
        // set the sequence constraints in the graph object
        void set_constraints(Graph& g, std::string constraints);
        // implementation of the function above, just returns incompatible positions and throws an error if requested
        std::vector<int> set_constraints(Graph& g, std::string constraints, bool throwerror);
    }
}
#endif


/* 
 * \endcond INTERNAL
 */
