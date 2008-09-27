/*
  Copyright (c) 2008 Robert G. Jakabosky
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.

  MIT License: http://www.opensource.org/licenses/mit-license.php
*/

#ifndef LLVMDUMPER_h
#define LLVMDUMPER_h

#include "lua_core.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "lobject.h"

#ifdef __cplusplus
}
#endif

namespace llvm {
class Module;
class Type;
class StructType;
class FunctionType;
class Constant;
class GlobalVariable;
}

class LLVMCompiler;

class LLVMDumper {
private:
	LLVMCompiler *compiler;
	llvm::Module *TheModule;

	// types.
	const llvm::Type *Ty_str_ptr;
	const llvm::StructType *Ty_constant_num_type;
	const llvm::StructType *Ty_constant_bool_type;
	const llvm::StructType *Ty_constant_str_type;
	const llvm::Type *Ty_constant_type_ptr;
	const llvm::StructType *Ty_jit_proto;
	const llvm::Type *Ty_jit_proto_ptr;
	const llvm::FunctionType *lua_func_type;
	const llvm::Type *lua_func_type_ptr;
	int max_alignment;

public:
	LLVMDumper(LLVMCompiler *compiler);

	void dump(const char *output, Proto *p, int optimize, int stripping);

private:
	llvm::Constant *get_ptr(llvm::Constant *val);

	llvm::Constant *get_global_str(const char *str);

	llvm::GlobalVariable *dump_constants(Proto *p);

	llvm::Constant *dump_proto(Proto *p);

	void dump_protos(Proto *p);

};
#endif

