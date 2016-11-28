SC_MODULE(CPU) {
public:
	sc_in<bool> Port_CLK;
	sc_in<Memory::RetCode> Port_MemDone;
	sc_out<Memory::Function> Port_MemFunc;
	sc_out<int> Port_MemAddr;
	sc_inout_rv<32> Port_MemData;

	SC_CTOR(CPU) {
		SC_THREAD(execute);
		sensitive << Port_CLK.pos();
		dont_initialize();
	}
private:
	void execute() {
		while (true) {
			wait();
			Memory::Function f =
					(rand() % 10) < 5 ? Memory::FUNC_READ : Memory::FUNC_WRITE;
			int addr = (rand() % MEM_SIZE);

			Port_MemAddr.write(addr);
			Port_MemFunc.write(f);
			if (f == Memory::FUNC_WRITE) {
				Port_MemData.write(rand());
				wait();
				Port_MemData.write(
						"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ");
			}
			wait(Port_MemDone.value_changed_event());
			// Advance one cycle in simulated time
			wait();
		}
	}
};
