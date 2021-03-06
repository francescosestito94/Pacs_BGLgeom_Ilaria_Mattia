/*======================================================================
                        "BGLgeom library"
        Course on Advanced Programming for Scientific Computing
                      Politecnico di Milano
                          A.Y. 2015-2016
                  
         Copyright (C) 2017 Ilaria Speranza & Mattia Tantardini
======================================================================*/
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/*!
	@file	boundary_condition.cpp
	@author	Ilaria Speranza & Mattia Tantardini
	@date	Jan, 2017
	@brief	Implementation of input and output operator for the boundary 
			condition struct
*/

#include "boundary_conditions.hpp"
#include <string>
#include <iostream>
#include <iomanip>

using namespace BGLgeom;

namespace BGLgeom{

std::istream & operator>>(std::istream & in, boundary_condition & BC){
	std::string type;
	in >> type;
	if(type == "NONE"){	// we suppose that there is a zero after the type. However, we check
		BC.type = BC_type::NONE;		
		in >> BC.value;
		if(BC.value != .0)
			BC.value = .0;
		return in;
	} else if(type == "INT"){
			BC.type = BC_type::INT;
			in >> BC.value;
			if(BC.value != .0)
				BC.value = .0;
		return in;
	} else if(type == "DIR"){
			BC.type = BC_type::DIR;
			in >> BC.value;
		return in;
	} else if(type == "NEU"){
			BC.type = BC_type::NEU;
			in >> BC.value;
		return in;
	} else if(type == "MIX"){
			BC.type = BC_type::MIX;
			in >> BC.value;
		return in;
	} else if(type == "OTHER"){
			BC.type = BC_type::OTHER;
			in >> BC.value;
		return in;
	}
	// Should not reach this
	std::cerr << "BGLgeom::boundary_conditions: Something wrong in input operation." << std::endl;
	return in;
}	//operator>>


std::ostream & operator<<(std::ostream & out, boundary_condition const& BC){	
	if(BC.type == BC_type::NONE){
		out << "BC NONE";
		return out;
	} else if(BC.type == BC_type::INT){
		out << "BC INT";
		return out;
	} else if(BC.type == BC_type::DIR){
		out << "BC DIR " << std::fixed << std::setprecision(8) << BC.value;
		return out;
	} else if(BC.type == BC_type::NEU){
		out << "BC NEU " << std::fixed << std::setprecision(8) << BC.value;
		return out;
	} else if(BC.type == BC_type::MIX){
		out << "BC MIX " << std::fixed << std::setprecision(8) << BC.value;
		return out;
	} else if(BC.type == BC_type::OTHER){
		out << "BC OTHER " << std::fixed << std::setprecision(8) << BC.value;
		return out;
	}
	// Should not reach this
	std::cerr << "BGLgeom::boundary_conditions: something wrong in output operation." << std::endl;
	return out;
}	//operator<<

}	//BGlgeom
