package rn;

#if cpp
	import cpp.Lib;
#elseif neko
	import neko.Lib;
#end

class LibModbus {
	public static var lmbNewTcp:String->Int->Void = Lib.load("libmodbus", "lmbNewTcp", 2);
	public static var lmbNewRtu:String->Int->String->Int->Int->Void = Lib.load("libmodbus", "lmbNewRtu", 5);
	public static var lmbConnect:Void->Int = Lib.load("libmodbus", "lmbConnect", 0);
	public static var lmbSetSlave:Int->Int = Lib.load("libmodbus", "lmbSetSlave", 1);
	public static var lmbReadRegisters:Int->Int->Int = Lib.load("libmodbus", "lmbReadRegisters", 2);
	public static var lmbGetTabReg:Int->Array<Int> = Lib.load("libmodbus", "lmbGetTabReg", 1);
	public static var lmbWriteRegister:Int->Int->Int = Lib.load("libmodbus", "lmbWriteRegister", 2);
	public static var lmbWriteRegisters:Int->Array<Int>->Int = Lib.load("libmodbus", "lmbWriteRegisters", 2);
	public static var lmbClose:Void->Void = Lib.load("libmodbus", "lmbClose", 0);
	public static var lmbFree:Void->Void = Lib.load("libmodbus", "lmbFree", 0);
}
