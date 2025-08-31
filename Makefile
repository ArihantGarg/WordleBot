compile :
	@g++ main.cpp -o main

execute : 
	@./main

clean : 
	@rm main

run :
	@clear
	@$(MAKE) compile
	@$(MAKE) execute
	@$(MAKE) clean

	

