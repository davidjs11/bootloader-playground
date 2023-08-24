[bits 16]
; these functions use int 10,E BIOS interrupt
; documentation: https://stanislavs.org/helppc/int_10-e.html

; print.asm
; prints a ASCII string into the screen
; parameters:
;   'bx' - pointer to the array to print
;   all strings must finish with 0x00 byte
print:
    pusha           ; push all registers into stack
    mov ah, 0x0E    ; set TTY mode

print_start:
    mov al, [bx]    ; check if current character is 0x00
    cmp al, 0x00
    je print_end

    int 0x10        ; print value 
    add bx, 1       ; increment 'bx' pointer
    jmp print_start ; continue loop

print_end:
    popa            ; recover registers from stack
    ret             ; finish function


; prints a new line
; no parameters needed
newline:
    pusha           ; push registers into stack
    mov ax, 0x0E0A  ; new line character
    int 0x10
    mov ax, 0x0E0D  ; carriage return
    int 0x10
    popa            ; recover registers from stack
    ret             ; finish function
