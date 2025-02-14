g++ -I../include -o image image.cpp    # Compile the C++ code
./image                                # Run the compiled program (this should generate output.tga)
sleep 5                                # Wait for 5 seconds
gimp output.tga 