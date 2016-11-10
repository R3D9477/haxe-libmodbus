#define IMPLEMENT_API
#define NEKO_COMPATIBLE

#include <hx/CFFI.h>
#include <stdio.h>
#include <stdlib.h>
#include </usr/include/modbus/modbus.h>

extern "C" {
	modbus_t* ctx;
	uint16_t tab_reg[32];
	
	void lmbNewTcp (value ip, value port) {
		ctx = modbus_new_tcp(val_string(ip), val_int(port));
	}
	DEFINE_PRIM(lmbNewTcp, 2);
	
	void lmbNewRtu (value device, value baud, value parity, value data_bit, value stop_bit) {
		ctx = modbus_new_rtu(val_string(device), val_int(baud), val_string(parity)[0], val_int(data_bit), val_int(stop_bit));
	}
	DEFINE_PRIM(lmbNewRtu, 5);
	
	value lmbConnect () {
		return alloc_int(modbus_connect(ctx));
	}
	DEFINE_PRIM(lmbConnect, 0);
	
	value lmbSetSlave (value slave) {
		return alloc_int(modbus_set_slave(ctx, val_int(slave)));
	}
	DEFINE_PRIM(lmbSetSlave, 1);
	
	value lmbReadRegisters (value addr, value nb) {
		return alloc_int(modbus_read_registers(ctx, val_int(addr), val_int(nb), tab_reg));
	}
	DEFINE_PRIM(lmbReadRegisters, 2);
	
	value lmbGetTabReg (value nb) {
		value a = alloc_array(val_int(nb));
		
		for (int i = 0; i < val_int(nb); i++)
			val_array_set_i(a, i, alloc_int(tab_reg[i]));
		
		return a;
	}
	DEFINE_PRIM(lmbGetTabReg, 1);
	
	value lmbWriteRegister (value addr, value v) {
		return alloc_int(modbus_write_register(ctx, val_int(addr), val_int(v)));
	}
	DEFINE_PRIM(lmbWriteRegister, 2);
	
	value lmbWriteRegisters (value addr, value src) {
		int size = val_array_size(src);
		uint16_t* src_u = static_cast<uint16_t*>(malloc(size * sizeof(uint16_t)));
		
		for (int i = 0; i < size; i++)
			src_u[i] = (uint16_t)val_int(val_array_i(src, i));
		
		int res = modbus_write_registers(ctx, val_int(addr), size, src_u);
		
		free(src_u);
		
		return alloc_int(res);
	}
	DEFINE_PRIM(lmbWriteRegisters, 2);
	
	void lmbClose () {
		modbus_close(ctx);
	}
	DEFINE_PRIM(lmbClose, 0);
	
	void lmbFree () {
		modbus_free(ctx);
	}
	DEFINE_PRIM(lmbFree, 0);
}
