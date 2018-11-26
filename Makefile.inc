# ====================================================================
#   					"BGLgeom library"
#      Course on Advanced Programming for Scientific Computing
#                     Politecnico di Milano
#                         A.Y. 2015-2016
#
#		Copyright (C) 2017 Ilaria Speranza & Mattia Tantardini
#=====================================================================

### USER CONFIGURATION VARIABLES ###
# Directory where the project resides.
PROJECT_DIR = $(HOME)/Documents/PACS/Pacs_BGLgeom_Ilaria_Mattia

# Installation path
INSTALL_PATH = $(HOME)/opt/BGLgeom

# Path to Boost Graph Library
export mkBGLInc = /opt/local/include

# Path to GetFEM main folder
export mkGetFEMHome =

# Path to MANworks main folder
export mkMANworksHome =

# Tolenrance on being zero (for comparison on points and segments)
# This variable is needed when including point.hpp and intersections2D.hpp headers,
# and this happens for all tests in the library and in both applications. If you do
# not want to set this value, a default one is provided.
TOL_VALUE = 1e-10

## EDIT THESE ONLY IF YOU DO NOT USE MODULE SYSTEM OF MOX CLUSTER ##
# Path to VTK includes
export mkVtkInc   = /opt/local/include/vtk-8.1
# Path to VTK libraries
export mkVtkLib   = /opt/local/lib
# Path to Eigen includes
export mkEigenInc = /opt/local/include/eigen3

# Variable SONAME
SONAME = install_name# For OSX
#SONAME = soname# For Linux
### NOW DO NOT EDIT ANYTHING ###

# Path to GetFEM library
GETFEM_LIB_DIR   = $(mkGetFEMHome)/lib
# Path to GetFEM includes
GETFEM_INC_DIR   = $(mkGetFEMHome)/include
# Path to MANworks library
MANWORKS_LIB_DIR = $(mkMANworksHome)/lib
# Path to Manworks includes
MANWORKS_INC_DIR = $(mkMANworksHome)/include
# Path to Eigen includes
EIGEN_INC_DIR    = $(mkEigenInc)
# Path to VTK includes
VTK_INC_DIR      = $(mkVtkInc)
# Path to VTK library
VTK_LIB_DIR      = $(mkVtkLib)
# Path to BGL includes
BGL_INC_DIR      = $(mkBGLInc)

## Project Folders
# libBGLgeom is stored here (we consider the installation path)
BGLGEOM_DIR = $(INSTALL_PATH)
# Example on network diffusion is stored here
NETW_DIR    = $(PROJECT_DIR)/network_diffusion
# Example on fracture intersection is sotred here
FRAC_DIR    = $(PROJECT_DIR)/fracture_intersection

# Parsing vtk libraries. In the modules are present also libraries for Python. We filter them out
#VTK_LIBS1 = $(wildcard $(VTK_LIB_DIR)/libvtk*.so.5.10.1) #collecting all libraries
VTK_LIBS1 = $(wildcard $(VTK_LIB_DIR)/libvtk*-8.1.dylib) #collecting all libraries
VTK_LIBS2 = $(notdir $(VTK_LIBS1))
VTK_LIBS3 = $(basename $(basename $(basename $(basename $(VTK_LIBS2))))) #Discarding .so.5.10.1
VTK_LIBS4 = $(foreach lib, $(VTK_LIBS3), $(if $(findstring Python, $(lib)),,$(lib)))
VTK_LIBS5  = $(VTK_LIBS4:lib%=%)
VTK_LIBS = vtkChartsCore-8.1  vtkCommonColor-8.1  vtkCommonComputationalGeometry-8.1  vtkCommonCore-8.1  vtkCommonDataModel-8.1  vtkCommonExecutionModel-8.1  vtkCommonMath-8.1  vtkCommonMisc-8.1  vtkCommonSystem-8.1  vtkCommonTransforms-8.1  vtkDICOMParser-8.1  vtkDomainsChemistry-8.1  vtkDomainsChemistryOpenGL2-8.1  vtkFiltersAMR-8.1  vtkFiltersCore-8.1  vtkFiltersExtraction-8.1  vtkFiltersFlowPaths-8.1  vtkFiltersGeneral-8.1  vtkFiltersGeneric-8.1  vtkFiltersGeometry-8.1  vtkFiltersHybrid-8.1  vtkFiltersHyperTree-8.1  vtkFiltersImaging-8.1  vtkFiltersModeling-8.1  vtkFiltersParallel-8.1  vtkFiltersParallelImaging-8.1  vtkFiltersPoints-8.1  vtkFiltersProgrammable-8.1  vtkFiltersSMP-8.1  vtkFiltersSelection-8.1  vtkFiltersSources-8.1  vtkFiltersStatistics-8.1  vtkFiltersTexture-8.1  vtkFiltersTopology-8.1  vtkFiltersVerdict-8.1  vtkGeovisCore-8.1  vtkIOAMR-8.1  vtkIOCore-8.1  vtkIOEnSight-8.1  vtkIOExodus-8.1  vtkIOExport-8.1  vtkIOExportOpenGL2-8.1  vtkIOGeometry-8.1  vtkIOImage-8.1  vtkIOImport-8.1  vtkIOInfovis-8.1  vtkIOLSDyna-8.1  vtkIOLegacy-8.1  vtkIOMINC-8.1  vtkIOMovie-8.1  vtkIONetCDF-8.1  vtkIOPLY-8.1  vtkIOParallel-8.1  vtkIOParallelXML-8.1  vtkIOSQL-8.1  vtkIOTecplotTable-8.1  vtkIOVideo-8.1  vtkIOXML-8.1  vtkIOXMLParser-8.1  vtkImagingColor-8.1  vtkImagingCore-8.1  vtkImagingFourier-8.1  vtkImagingGeneral-8.1  vtkImagingHybrid-8.1  vtkImagingMath-8.1  vtkImagingMorphological-8.1  vtkImagingSources-8.1  vtkImagingStatistics-8.1  vtkImagingStencil-8.1  vtkInfovisCore-8.1  vtkInfovisLayout-8.1  vtkInteractionImage-8.1  vtkInteractionStyle-8.1  vtkInteractionWidgets-8.1  vtkNetCDF-8.1  vtkParallelCore-8.1  vtkRenderingAnnotation-8.1  vtkRenderingContext2D-8.1  vtkRenderingContextOpenGL2-8.1  vtkRenderingCore-8.1  vtkRenderingFreeType-8.1  vtkRenderingGL2PSOpenGL2-8.1  vtkRenderingImage-8.1  vtkRenderingLOD-8.1  vtkRenderingLabel-8.1  vtkRenderingOpenGL2-8.1  vtkRenderingVolume-8.1  vtkRenderingVolumeOpenGL2-8.1  vtkViewsContext2D-8.1  vtkViewsCore-8.1  vtkViewsInfovis-8.1  vtkalglib-8.1  vtkexoIIc-8.1  vtkexpat-8.1  vtkfreetype-8.1  vtkgl2ps-8.1  vtkglew-8.1  vtkhdf5-8.1  vtkhdf5_hl-8.1  vtkjpeg-8.1  vtkjsoncpp-8.1  vtklibharu-8.1  vtklibxml2-8.1  vtklz4-8.1  vtkmetaio-8.1  vtknetcdfcpp-8.1  vtkoggtheora-8.1  vtkpng-8.1  vtkproj4-8.1  vtksqlite-8.1  vtksys-8.1  vtktiff-8.1  vtkverdict-8.1  vtkzlib-8.1
## Libraries needed to the linker
# For all code
LDLIBS = -L$(VTK_LIB_DIR) $(foreach lib, $(VTK_LIBS), -l$(lib))
# Specific for network_diffusion application
LDLIBS_DIFF = -L$(GETFEM_LIB_DIR) -lgetfem -L$(MANWORKS_LIB_DIR) -lproblem3d1d

# Collect all includes
ALL_INC_DIR= $(EIGEN_INC_DIR) $(VTK_INC_DIR) $(BGL_INC_DIR)
includes := $(foreach inc,$(ALL_INC_DIR),-I$(inc))
INCLUDES += -I. -I./include $(includes)
# Includes specific for netwrok_diffusion application
INC_DIR_DIFF = $(GETFEM_INC_DIR) $(MANWORKS_INC_DIR)
includes_diff := $(foreach inc, $(INC_DIR_DIFF),-I$(inc))
INCLUDES_DIFF += -I. -I./include $(includes_diff)

# Compiler and standard for the compiler
CXX = g++
STDFLAG = -std=c++11

# DEFINES: Possible -DXX statements
# TOL: Tolerance on being zero. Used to check distances for points and segments, mainly.
DEFINES += -DTOL=$(TOL_VALUE)

# OPT: Level of optimization
# REALESE: Allows to choose the level of optimization. If set (RELEASE=yes when compiling), full optimization, otherwise debug mode
ifdef RELEASE
OPT = -O3
DEFINES += -DNDEBUG
else
OPT = -g
endif

# Warning level. The option -Wno-deprecated deactivates annoying warning from BGL
WARNS = -Wall -Wno-deprecated

export CPPFLAGS = $(DEFINES) $(INCLUDES)
export CXXFLAGS = $(STDFLAG) $(WARNS) $(OPT)
