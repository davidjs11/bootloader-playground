; defines the global descriptor table
; not explaining it here due to its complexity
; for more info: https://wiki.osdev.org/GDT

; gdt.asm
gdt_start:  ; start-label

; --- null-descriptor -----------------------
gdt_null:
    dd 0x0 ; just 8 null bytes
    dd 0x0


; --- code segment descriptor ---------------
; base: 0x0
; limit: 0xFFFFF
; present: 1
; privilege: 00b
; descriptor type: 1
; type:
;   - code: 1
;   - conforming: 0
;   - readable: 1
;   - accessed: 0
; flags:
;   - granularity: 1
;   - 32-bit: 1
;   - 64-bit: 0
;   - avl: 0
; -------------------------------------------
; segment binary
; 0000 0000 1100 1111 1001 1010 0000 0000
; 0000 0000 0000 0000 1111 1111 1111 1111

gdt_code:
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 10011010b
    db 11001111b
    db 0x00


; --- data segment descriptor ---------------
; base: 0x0
; limit: 0xFFFFF
; present: 1
; privilege: 00b
; descriptor type: 1
; type:
;   - code: 0
;   - expand-down: 0
;   - writable: 1
;   - accessed: 0
; flags:
;   - granularity: 1
;   - 32-bit: 1
;   - 64-bit: 0
;   - avl: 0
; -------------------------------------------
; segment binary
; 0000 0000 1100 1111 1001 0010 0000 0000
; 0000 0000 0000 0000 1111 1111 1111 1111

gdt_data:
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 10010010b
    db 11001111b
    db 0x00

gdt_end:    ; end-label


; --- gdt descriptor ------------------------
; 16 bits -> size
; 32 bits -> address
gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start


; --- constants -----------------------------
CODE_SEGMENT equ gdt_code - gdt_start
DATA_SEGMENT equ gdt_data - gdt_start


; --- current GDT ---------------------------
; (0x00) -> NULL
; (0x08) -> CODE
; (0x10) -> DATA
; -------------------------------------------
