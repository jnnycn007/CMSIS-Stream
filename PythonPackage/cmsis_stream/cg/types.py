###########################################
# Project:      CMSIS DSP Library
# Title:        types.py
# Description:  Description of the basic CMSIS-DSP types
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
"""Description of the basic types recognized by the tool"""

from html import escape

F64    = 1
F32    = 2
F16    = 3
Q31    = 4
Q15    = 5
Q7     = 6
UINT32 = 7
UINT16 = 8
UINT8  = 9
SINT32 = 10
SINT16 = 11
SINT8  = 12

class CGStaticType:
    """Descrition of a type used to fill a FIFO"""

    def __init__(self):
      self._shared = False

    def __eq__(self, other):
        """Check if this type is equal to another type.
           Two types are equal if they have same class.

           Size differences are handled by the FIFOs ...
        """
        return(self.__class__ == other.__class__)

    @property
    def bytes(self):
       return(0)

    @property
    def fillValue(self):
        return(0)

    @property
    def shared(self):
       return self._shared

    def share(self):
      return(self)

    def unique(self):
       return(self)

class EventType(CGStaticType):
   def __init__(self):
        CGStaticType.__init__(self)
        self._name="EVENT" 
        # Not used for events that are not going through the data FIFOs
        self._size_in_bytes=0

   def __eq__(self, other):
      return(CGStaticType.__eq__(self,other) and self._name == other._name)

   @property
   def fillValue(self):
        return("None") 

   @property
   def bytes(self):
       return(self._size_in_bytes)

   @property
   def ctype(self):
      return("Event")

   @property
   def nptype(self):
      return("object")

   @property
   def graphViztype(self):
      return(escape(self._name))   

class CStructType(CGStaticType):
   """A C structure

      All structures with same name must have same size in bytes
      Name must be a valid C and Python identifier
   """
   def __init__(self,name,size_in_bytes):
        CGStaticType.__init__(self)
        self._name=name 
        self._size_in_bytes=size_in_bytes

   def __eq__(self, other):
      return(CGStaticType.__eq__(self,other) and self._name == other._name)

   @property
   def fillValue(self):
        return("None") 

   @property
   def bytes(self):
       return(self._size_in_bytes)

   @property
   def ctype(self):
      return(self._name)

   @property
   def nptype(self):
      return("object")

   @property
   def graphViztype(self):
      return(escape(self._name))

class CCustomType(CStructType):
   pass

class SharedType(CGStaticType):
   def __init__(self,refType):
      CGStaticType.__init__(self)
      self._refType = refType
      self._shared = False

   def __eq__(self, other):
      samePythonClass = CGStaticType.__eq__(self,other) 
      if samePythonClass:
         sameUnderlyingType = self._refType == other._refType 
         # Compatibility of shared status is enforced by the C++
         # templates
         return(samePythonClass and sameUnderlyingType)
      else:
         return(False)

   def _shareBool(self):
      if self.shared:
         return("true")
      else:
         return("false")

   @property
   def fillValue(self):
        return("None") 

   @property
   def bytes(self):
       return(self._refType.bytes)

   @property
   def ctype(self):
      return(f"Shared<{self._refType.ctype},{self._shareBool()}>")

   @property
   def nptype(self):
      return("object")

   @property
   def graphViztype(self):
      return(escape(f"Shared<{self._refType.ctype},{self._shareBool()}>"))

   def share(self):
       r = SharedType(self._refType)
       r._shared = True 
       return(r)

   def unique(self):
       r = SharedType(self._refType)
       return(r)
      

class PythonClassType(CGStaticType):
   """A Python class

   """
   def __init__(self,python_name):
        CGStaticType.__init__(self)
        self._python_name=python_name 

   def __eq__(self, other):
      return(CGStaticType.__eq__(self,other) and self._python_name == other._python_name)

   @property
   def fillValue(self):
        return("%s()" % self._python_name) 

   @property
   def bytes(self):
       return(0)

   @property
   def ctype(self):
      return("void")

   @property
   def nptype(self):
      return("object")

   @property
   def graphViztype(self):
      return(escape(self._python_name))

class CType(CGStaticType):
    """A C Scalar element"""
    def __init__(self,typeid,cmsis_dsp=False):
        CGStaticType.__init__(self)
        self._cmsisdsp = cmsis_dsp
        self._id=typeid 

    @property
    def bytes(self):
        if self._id == F64:
           return(8)
        elif self._id == F32:
           return(4)
        elif self._id == F16:
           return(2)
        elif self._id == Q31:
           return(4)
        elif self._id == Q15:
           return(2)
        elif self._id == Q7:
           return(1)
        elif self._id == UINT32:
           return(4)
        elif self._id == UINT16:
           return(2)
        elif self._id == UINT8:
           return(1)
        elif self._id == SINT32:
           return(4)
        elif self._id == SINT16:
           return(2)
        elif self._id == SINT8:
           return(1)
        else:
           return(0)

    @property
    def ctype(self):
        if self._id == F64:
           if self._cmsisdsp:
              return("float64_t")
           else:
              return("double")
        elif self._id == F32:
           if self._cmsisdsp:
              return("float32_t")
           else:
              return("float")
        elif self._id == F16:
           return("float16_t")
        elif self._id == Q31:
           return("q31_t")
        elif self._id == Q15:
           return("q15_t")
        elif self._id == Q7:
           return("q7_t")
        elif self._id == UINT32:
           return("uint32_t")
        elif self._id == UINT16:
           return("uint16_t")
        elif self._id == UINT8:
           return("uint8_t")
        elif self._id == SINT32:
           return("int32_t")
        elif self._id == SINT16:
           return("int16_t")
        elif self._id == SINT8:
           return("int8_t")
        else:
           return("void")

    @property
    def nptype(self):
        if self._id == F64:
           return("np.float64")
        elif self._id == F32:
           return("np.float32")
        elif self._id == F16:
           return("np.float16")
        elif self._id == Q31:
           return("np.int32")
        elif self._id == Q15:
           return("np.int16")
        elif self._id == Q7:
           return("np.int8")
        elif self._id == UINT32:
           return("np.uint32")
        elif self._id == UINT16:
           return("uint16")
        elif self._id == UINT8:
           return("np.uint8")
        elif self._id == SINT32:
           return("np.int32")
        elif self._id == SINT16:
           return("np.int16")
        elif self._id == SINT8:
           return("np.int8")
        else:
           return("void")

    @property
    def graphViztype(self):
        if self._id == F64:
           return("f64")
        elif self._id == F32:
           return("f32")
        elif self._id == F16:
           return("f16")
        elif self._id == Q31:
           return("q31")
        elif self._id == Q15:
           return("q15")
        elif self._id == Q7:
           return("q7")
        elif self._id == UINT32:
           return("u32")
        elif self._id == UINT16:
           return("u16")
        elif self._id == UINT8:
           return("u8")
        elif self._id == SINT32:
           return("s32")
        elif self._id == SINT16:
           return("s16")
        elif self._id == SINT8:
           return("s8")
        else:
           return("void")

    @property
    def dspExtension(self):
        if self._id == F64:
           return("f64")
        elif self._id == F32:
           return("f32")
        elif self._id == F16:
           return("f16")
        elif self._id == Q31:
           return("q31")
        elif self._id == Q15:
           return("q15")
        elif self._id == Q7:
           return("q7")
        elif self._id == UINT32:
           return("u32")
        elif self._id == UINT16:
           return("u16")
        elif self._id == UINT8:
           return("u8")
        elif self._id == SINT32:
           return("s32")
        elif self._id == SINT16:
           return("s16")
        elif self._id == SINT8:
           return("s8")
        else:
           return("void")

    def __eq__(self, other):
      return(CGStaticType.__eq__(self,other) and self._id == other._id)


