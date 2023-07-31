; these functions use int 10,E BIOS interrupt
; documentation: https://stanislavs.org/helppc/int_10-e.html

; print.asm
; prints a ASCII string into the screen
; parameters:
;   'bx' - pointer to the array to print
;   all strings must finish with 0x00 byte
print:
    pusha   ; push all registers into stack

print_start:
    ; check if the value pointed by bx is 0x00
    mov al, [bx]
    cmp al, 0x00
    je print_end

    ; print the value stored in 'al'
    mov ah, 0x0E    ; set TTY mode
    int 0x10        ; print value 

    ; increment address in 'bx'
    add bx, 1
    jmp print_start

print_end:
    popa    ; recover registers from stack
    ret     ; finish function


; prints a new line
; no parameters needed
newline:
    pusha   ; push registers into stack
    mov ax, 0x0E0A  ; new line character
    int 0x10
    mov ax, 0x0E0D  ; carriage return
    int 0x10
    popa    ; recover registers from stack
    ret     ; finish function
