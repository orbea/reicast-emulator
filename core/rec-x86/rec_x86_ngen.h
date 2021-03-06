#include "types.h"

#include "hw/sh4/sh4_opcode_list.h"
#include "hw/sh4/modules/ccn.h"
#include "hw/sh4/sh4_interrupts.h"

#include "hw/sh4/sh4_core.h"
#include "hw/sh4/dyna/ngen.h"
#include "hw/sh4/sh4_mem.h"
#include "hw/sh4/dyna/regalloc.h"
#include "emitter/x86_emitter.h"

#ifdef __cplusplus
extern "C" {
#endif

void ngen_opcode(RuntimeBlockInfo* block, shil_opcode* op,x86_block* x86e, bool staging, bool optimise);

void ngen_LinkBlock_Shared_stub(void);
void ngen_LinkBlock_Generic_stub(void);
void ngen_LinkBlock_cond_Next_stub(void);
void ngen_LinkBlock_cond_Branch_stub(void);
void ngen_FailedToFindBlock_(void);
void ngen_mainloop(void* cntx);


void DYNACALL ngen_blockcheckfail(u32 addr);
void DYNACALL ngen_blockcheckfail2(u32 addr);

extern x86_block* x86e;

extern int cycle_counter;

extern void* loop_no_update;
extern void* intc_sched;

extern bool sse_1;
extern bool sse_2;
extern bool sse_3;
extern bool ssse_3;
extern bool mmx;

#ifdef __cplusplus
}
#endif


struct x86_reg_alloc: RegAlloc<x86_reg,x86_reg>
{
	virtual void Preload(u32 reg,x86_reg nreg);
	virtual void Writeback(u32 reg,x86_reg nreg);
	virtual void Preload_FPU(u32 reg,x86_reg nreg);
	virtual void Writeback_FPU(u32 reg,x86_reg nreg);
	void FreezeXMM();
	void ThawXMM();
};

extern x86_reg_alloc reg;


