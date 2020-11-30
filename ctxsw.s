	AREA CTXSW, CODE, READONLY

    EXPORT first_context
    EXPORT switch_context

first_context	MOV sp, r0
				POP {r8-r12}
				POP {r4-r7,pc}


switch_context	MOV sp, r0
				PUSH {lr}
				PUSH {r4-r7}
				PUSH {r8-r12}	;stackpointer alt ändert sich nicht mehr
				
				MOV sp, r1		;neuer stackpointer
				POP {r8-r12}
				POP {r4-r7,pc}

    END
