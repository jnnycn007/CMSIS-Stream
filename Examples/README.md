## How to build the examples

First, you must install the `CMSIS-Stream` package:

```
pip install cmsis-stream
```

The Python functions and classes inside the `cmsis-stream` package can be used to describe and generate the schedule.

You need a recent Graphviz dot tool supporting the HTML-like labels. You'll need `cmake` and `make`

In folder `ComputeGraph/example/build`, type the `cmake` command:

```bash
cmake -DHOST=YES \
   -DDOT="path to dot.EXE" \
   -DCMSISDSP="path to cmsis dsp" \
   -DHOST=YES \
   -G "Unix Makefiles" ..
```

If cmake is successful, you can type `make` to build the examples. It will also build CMSIS-DSP for the host.

If you don't have graphviz, the option -DDOT can be removed.

If for some reason it does not work, you can go into an example folder (for instance example1), and type the commands:

```bash
python graph.py 
dot -Tpdf -o test.pdf test.dot
```

It will generate the C++ files for the schedule and a pdf representation of the graph.

Note that the Python code is relying on the `cmsis-stream` package.

For `example3` which is using an input file, `cmake` should have copied the input test pattern `input_example3.txt` inside the build folder. The output file will also be generated in the build folder.

`example4` is like `example3` but in pure Python and using the CMSIS-DSP Python wrapper (which must already be installed before trying the example). To run a Python example, you need to go into an example folder and type:

```bash
python main.py
```

`example7` is communicating with `OpenModelica`. You need to install the VHTModelica blocks from the [AVH-SystemModeling](https://github.com/ARM-software/VHT-SystemModeling) project on our GitHub

# List of examples

* [Simple example without CMSIS-DSP](simple/README.md) : **How to get started**
* [Simple example with CMSIS-DSP](simpledsp/README.md) : **How to get started with CMSIS-DSP**
* [Example 1](example1/README.md) : Same as the simple example but explaining how to add arguments to the scheduler API and node constructors. This example is also giving a **detailed explanation of the C++ code** generated for the scheduler
* [Example 2](example2/README.md) : Explain how to use CMSIS-DSP pure functions (no state) and add delay on the arcs of the graph. Explain some configuration options for the schedule generation.
* [Example 3](example3/README.md) : A full signal processing example with CMSIS-DSP using FFT and sliding windows and overlap and add node
* Example 4 : Python code generation (deprecated and removed)
* Example 5 : Python code generation (deprecated and removed)
* [Example 6](example6/README.md) : Same as example 5 but with C++ code generation
* Example 7 : Python code generation (deprecated and removed)
* [Example 8](example8/README.md) : Introduce structured datatype for the samples and implicit `Duplicate` nodes for the graph
* [Example 9](example9/README.md) : Check that duplicate nodes and arc delays are working together and a scheduling is generated
* [Example 10 : The dynamic dataflow mode](example10/README.md)
* [Cyclo-static scheduling](cyclo/README.md)
* [Simple example with the event recorder](eventrecorder/README.md)
* [runtime_mode](runtime_mode/README.md) : This example shows how to change the graph at runtime without recompiling

