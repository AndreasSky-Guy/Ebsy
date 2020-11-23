AREA  CTXSW, CODE, READONLY
	firstContext PROC    ; Assembler-Source (ctxsw.s)
	EXPORT firstContext
		MOV sp, r0
		POP {r8-r12}
		POP {r4-r7,pc}
		
	ENDP

	switchContext PROC    ; Assembler-Source (ctxsw.s)
	EXPORT switchContext
		
	ENDP