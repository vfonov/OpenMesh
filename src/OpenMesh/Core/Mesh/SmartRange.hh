/* ========================================================================= *
 *                                                                           *
 *                               OpenMesh                                    *
 *           Copyright (c) 2001-2019, RWTH-Aachen University                 *
 *           Department of Computer Graphics and Multimedia                  *
 *                          All rights reserved.                             *
 *                            www.openmesh.org                               *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * This file is part of OpenMesh.                                            *
 *---------------------------------------------------------------------------*
 *                                                                           *
 * Redistribution and use in source and binary forms, with or without        *
 * modification, are permitted provided that the following conditions        *
 * are met:                                                                  *
 *                                                                           *
 * 1. Redistributions of source code must retain the above copyright notice, *
 *    this list of conditions and the following disclaimer.                  *
 *                                                                           *
 * 2. Redistributions in binary form must reproduce the above copyright      *
 *    notice, this list of conditions and the following disclaimer in the    *
 *    documentation and/or other materials provided with the distribution.   *
 *                                                                           *
 * 3. Neither the name of the copyright holder nor the names of its          *
 *    contributors may be used to endorse or promote products derived from   *
 *    this software without specific prior written permission.               *
 *                                                                           *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED *
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A           *
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER *
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  *
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,       *
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR        *
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    *
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING      *
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS        *
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              *
 *                                                                           *
 * ========================================================================= */


#pragma once

#include <utility>

//== NAMESPACES ===============================================================

namespace OpenMesh {

//== FORWARD DECLARATION ======================================================

//== CLASS DEFINITION =========================================================

/// Base class for all smart range types
template <typename RangeT, typename HandleT>
struct SmartRangeT
{
  // TODO: Someone with better c++ knowledge may improve the code below.

  template <typename Functor>
  auto sum(Functor f) -> decltype (f(std::declval<HandleT>())+f(std::declval<HandleT>()))
  {
    auto range = static_cast<const RangeT*>(this);
    auto begin = range->begin();
    auto end   = range->end();
    assert(begin != end);
    decltype (f(*begin) + f(*begin)) sum = f(*begin);
    auto it = begin;
    ++it;
    for (; it != end; ++it)
      sum += f(*it);
    return sum;
  }

};



//=============================================================================
} // namespace OpenMesh
//=============================================================================

//=============================================================================
