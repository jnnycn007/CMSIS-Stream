###########################################
# Project:      CMSIS DSP Library
# Title:        config.py
# Description:  Configuration of the code generator
# 
# 
# Target Processor: Cortex-M and Cortex-A cores
# -------------------------------------------------------------------- */
# 
# Copyright (C) 2021-2023 ARM Limited or its affiliates. All rights reserved.
# 
# SPDX-License-Identifier: Apache-2.0
# 
# Licensed under the Apache License, Version 2.0 (the License); you may
# not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an AS IS BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
############################################
from jinja2 import Environment, PackageLoader, select_autoescape
import os.path
import os

"""Configuration of C code generation"""
class Configuration:

    def __init__(self):

        #########################
        #
        # SCHEDULING OPTIONS
        #

        # If FIFOs size must be dumped during computation of the schedule
        self.displayFIFOSizes=False

        # Experimental so disabled by default
        self.memoryOptimization = False

        # Give priority to sink with topological sort 
        self.sinkPriority = True

        # Print schedule in a human understandble form
        self.dumpSchedule = False

        # Following two options should be code generation options
        # but must currently be scheduling option
        # (rework needed to be able to use them only as code generation options)
        # Objects are allocated on the heap rather than stack
        self.heapAllocation = False

        # True if callback mode is used to call the scheduler
        # Switch case is implied so that the state machine
        # state can be saved / restore in the middle
        self.callback = False

        # Disable the memory optimization related to buffer
        # sharing between output and input FIFOs of
        # duplicate node
        # This feature is still experimental and in case of
        # bug the user must be able to disable it
        self.disableDuplicateOptimization =  False


        #############################
        #
        # GRAPHVIZ GENERATION OPTIONS
        #

        # True for an horizontal graphviz layout
        self.horizontal = True

        # Display FIFO buffers in graph instead of datatype
        self.displayFIFOBuf = False

        #########################
        #
        # CODE GENERATION OPTIONS
        #


        # Number of iterations of the schedule. By default it is infinite
        # represented by the value 0
        self.debugLimit = 0 

        # If FIFO content must be dumped during execution of the schedule.
        self.dumpFIFO = False

        # Name of scheduling function in the generated code
        # (Must be valid C and Python name)
        self.schedName = "scheduler"

        # Additional arguments for the scheduler API
        # must be valid C
        self.cOptionalArgs=""

        # Additional arguments for the scheduler API
        # must be valid C
        self.pyOptionalArgs=""

        # Prefix to add before the global FIFO buffer names
        self.prefix = ""

        # Path to CG  module for Python simu 
        self.pathToCGModule="../../.."

        # If users do not want to use function pointers,
        # we can generate a switch/case instead
        self.switchCase = True


        # Enable support for CMSIS Event Recorder 
        self.eventRecorder = False

        # Name of AppNode file
        self.appNodesCName = "AppNodes.h"
        self.appNodesPythonName = "appnodes"

        # Name of custom file
        self.customCName = "custom.h"
        self.customPythonName = "custom"

        # Name of post custom files
        self.postCustomCName = ""

        # Name of generic nodes headers
        self.genericNodeCName = "GenericNodes.h"

        # Name of cg_status header for error codes
        self.cgStatusCName = "cg_status.h"

        # Name of scheduler source and header files
        self.schedulerCFileName = "scheduler"
        self.schedulerPythonFileName = "sched"

        # True is C API for the scheduler
        self.CAPI = True

        # By default arm_math.h is included
        self.CMSISDSP = False

        # Asynchronous scheduling using
        # synchronous as first start
        # It implies switchCase
        # It disables memory optimizations
        # Also FIFO cannot be used any more as just
        # buffers.
        self.asynchronous = False

        # Asynchronous scheduling without reference to the
        # synchronous case
        # FIFO length must be provided
        # IO lengths ignored
        # Weak FIFO can be specified to remove loops for
        # topological order schedule
        # switchCase and disable memory optimizations
        self.fullyAsynchronous = False 


        # Increase in percent of the FIFOs.
        # Used in asynchronous mode
        # where the FIFOs may need to be bigger
        # than what is computed assuming a 
        # synchronous scheduling.
        self.FIFOIncrease = 0

        # Default asynchronous more for pure functions 
        # like CMSIS-DSP
        self.asyncDefaultSkip = True

        

        # Buffer are allocated through memory allocator
        self.bufferAllocation = False

        # When true, create a new C++ header only
        # with an array allowing to access the identified
        # nodes (identified is a node creation option true by default)
        # Macros are also generated to give indexes into this array
        # It implies heapAllocation true because nodes
        # must be available before the scheduler is started.
        self.nodeIdentification = False

        # Default graph coloring strategy for memory optimization algorithm
        # Values are from networkX library and can be:
        # 'largest_first'
        # 'random_sequential'
        # 'smallest_last'
        # 'independent_set'
        # 'connected_sequential_bfs'
        # 'connected_sequential_dfs'
        # 'saturation_largest_first'
        self.memStrategy = "largest_first"

        

       
    @property
    def debug(self):
        return (self.debugLimit > 0)
    

def generateGenericNodes(folder):
    env = Environment(
       loader=PackageLoader("cmsis_stream.cg.scheduler"),
       autoescape=select_autoescape(),
       trim_blocks=True
    )

    ctemplate = env.get_template("GenericNodes.h")
    path=os.path.join(folder,"GenericNodes.h")

    if not os.path.isfile(path):
        with open(path,"w") as f:
            print(ctemplate.render(),file=f)

def generateCGStatus(folder):
    env = Environment(
       loader=PackageLoader("cmsis_stream.cg.scheduler"),
       autoescape=select_autoescape(),
       trim_blocks=True
    )

    ctemplate = env.get_template("cg_status.h")
    path=os.path.join(folder,"cg_status.h")
    if not os.path.isfile(path):
       with open(path,"w") as f:
           print(ctemplate.render(),file=f)

def createEmptyProject(project_name):
    env = Environment(
       loader=PackageLoader("cmsis_stream.cg.scheduler","example"),
       autoescape=select_autoescape(),
       trim_blocks=True
    )
    try:
        os.mkdir(project_name)
    except Exception as e:
        pass

    all_files={"start_project_appnodes.h":"AppNodes.h"
              ,"start_project_custom.h":"custom.h"
              ,"start_project_main.c":"main_host.c"
              ,"start_project_graph.py":"graph.py"
              ,"Makefile.linux":"Makefile.linux"
              ,"Makefile.mac":"Makefile.mac"
              ,"Makefile.windows":"Makefile.windows"
              ,"main_board.c":"main.c"
              ,"simple_ac6.csolution.yml":"simple_ac6.csolution.yml"
              ,"simple.cproject.yml":"simple.cproject.yml"
              ,"vht.clayer.yml":"vht.clayer.yml"
              ,"run.bat":"run_vht.bat"
              ,"ARMCM55_FP_MVE_config.txt":"ARMCM55_FP_MVE_config.txt"
              ,"README.md":"README.md"};
    for src_name in all_files:
        dst_name = all_files[src_name]
        ctemplate = env.get_template(src_name)
        path = os.path.join(project_name,dst_name)
        with open(path,"w") as f:
            print(ctemplate.render(),file=f)