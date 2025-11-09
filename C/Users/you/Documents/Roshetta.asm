.data
message:         .asciiz "Enter your name: "
buffer:          .space 100
return_message:  .asciiz "Hello, "

.text
.globl main

main:
    # Print "Enter your name: "
    li $v0, 4
    la $a0, message
    syscall

    # Read user input into buffer
    li $v0, 8
    la $a0, buffer
    li $a1, 100
    syscall

    # Print "Hello, "
    li $v0, 4
    la $a0, return_message
    syscall

    # Print the entered name
    li $v0, 4
    la $a0, buffer
    syscall

    # Exit the program
    li $v0, 10
    syscall
