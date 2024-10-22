# COP 4530
# make file for assignment 2

# compile memory manager program
proj2.x: mem_manager.cpp MyMemory.h
	g++ -o proj2.x mem_manager.cpp

# execute memory manager program
run_proj2: proj2.x
	./proj2.x

# compile memory manager program
test_list.x: test_list.cpp List.h
	g++ -o  test_list.x test_list.cpp

# execute memory manager program
run_testlist: test_list.x
	./test_list.x

# clean
clean: 
	rm proj2.x test_list.x

