	AREA CTXSW, CODE, READONLY

    EXPORT first_context
	EXPORT save_context
	EXPORT load_context
	;EXPORT switch_context

first_context PROC
				LDR sp, [r0]
				POP {r8}
				POP {r9}
				POP {r10}
				POP {r11}
				POP {r12}
				;POP {r8-r12}
				POP {r4}
				POP {r5}
				POP {r6}
				POP {r7}
				;POP {r4-r7, pc}		
				POP {lr}
				STR sp, [r0]
				BX lr
				ENDP

save_context PROC
				POP {r1}    ; r4 pop
				POP {r1}    ; lr pop
				LDR sp, [r0]
				PUSH {r1}   ;lr push???
				PUSH {r7}
				PUSH {r6}
				PUSH {r5}
				PUSH {r4}
				;PUSH {r4-r7}
				PUSH {r12}
				PUSH {r11}
				PUSH {r10}
				PUSH {r9}
				PUSH {r8}
				STR sp, [r0]
				BX lr
				ENDP
					
				;PUSH {r8-r12}	;stackpointer alt ändert sich nicht mehr
load_context PROC			
				LDR sp, [r0]	;neuer stackpointer
				POP {r8}
				POP {r9}
				POP {r10}
				POP {r11}
				POP {r12}
				POP {r4}
				POP {r5}
				POP {r6}
				POP {r7}
				POP {lr}
				STR sp, [r0]
				BX lr
				;POP {r8-r12}
				;POP {r4-r7,pc}
				ENDP
;switch_context PROC
				;LDR sp, [r0]
				;PUSH {r2}
				;PUSH {r7}
				;PUSH {r6}
				;PUSH {r5}
				;PUSH {r4}
				;;PUSH {r4-r7}
				;PUSH {r12}
				;PUSH {r11}
				;PUSH {r10}
				;PUSH {r9}
				;PUSH {r8}
				;STR sp, [r0]
				
				;;PUSH {r8-r12}	;stackpointer alt ändert sich nicht mehr
				
				;LDR sp, [r1]	;neuer stackpointer
				;POP {r8}
				;POP {r9}
				;POP {r10}
				;POP {r11}
				;POP {r12}
				;POP {r4}
				;POP {r5}
				;POP {r6}
				;POP {r7}
				;POP {lr}
				;STR sp, [r1]
				;BX lr
				;;POP {r8-r12}
				;;POP {r4-r7,pc}
				;ENDP
			
    END
