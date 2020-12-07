	AREA CTXSW, CODE, READONLY

    EXPORT first_context
	EXPORT save_context
	EXPORT load_context

;/*  FUNCTION <first_context>

; ******************************************************************************
; *  PURPOSE:                                                                  *
; *   used to call first context											   *
; *                                                                            *
; ******************************************************************************
; *  PARAMETER:                                                                *
; *  	ProcessID 															   *
; *                                                                            *
; ******************************************************************************
; *  RETURN VALUE                                                              *
; *    result		                                                           *
; *                                                                            *
; ******************************************************************************
; *  CHANGE HISTORY:                                                           *
; *   Revision   Date          Author      			Description                *
; *      0       23.11.2020    Müller Dominik    creation                      *
; *      0       05.12.2020    Müller Dominik    revision                      *
; *                                                                            *
; ******************************************************************************/

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
				STR sp, [r0] ;stackpointer gets saved to adress in r0
				BX lr
				ENDP
					
;/*  FUNCTION <save_context>

; ******************************************************************************
; *  PURPOSE:                                                                  *
; *   used to save context to stack registers   							   *
; *                                                                            *
; ******************************************************************************
; *  PARAMETER:                                                                *
; *  	ProcessID 															   *
; *                                                                            *
; ******************************************************************************
; *  RETURN VALUE                                                              *
; *    result		                                                           *
; *                                                                            *
; ******************************************************************************
; *  CHANGE HISTORY:                                                           *
; *   Revision   Date          Author      			Description                *
; *      0       05.12.2020    Müller Dominik    creation                      *
; *                                                                            *
; ******************************************************************************/

save_context PROC
				POP {r1}    ; r4 pop
				POP {r1}    ; lr pop
				LDR sp, [r0] ; correct stackpointer gets set
				PUSH {r1}   ;lr push
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
				STR sp, [r0] ;stackpointer gets saved to adress in r0
				BX lr
				ENDP
					
				
;/*  FUNCTION <load_context>

; ******************************************************************************
; *  PURPOSE:                                                                  *
; *   used to load context saved from processes								   *
; *                                                                            *
; ******************************************************************************
; *  PARAMETER:                                                                *
; *  	ProcessID 															   *
; *                                                                            *
; ******************************************************************************
; *  RETURN VALUE                                                              *
; *    result		                                                           *
; *                                                                            *
; ******************************************************************************
; *  CHANGE HISTORY:                                                           *
; *   Revision   Date          Author      			Description                *
; *      0       05.12.2020    Müller Dominik    creation                      *
; *                                                                            *
; ******************************************************************************/				
				
load_context PROC			
				LDR sp, [r0]	;load stackpointer from parameter 1
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
				STR sp, [r0] ;stackpointer gets saved to adress in r0
				BX lr
				
				ENDP

			
    END
