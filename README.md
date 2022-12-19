printbin - A quick utility to print a number in it's binary representation.

Usage:

    Print binary representation:
        $ printbin 555
        |>  
    
    Print a 16 bit representation:

        $ printbin -b 16 -n 1234
        |>  00000100 11010010

    Print an 8 bit representation of a base 16 number
        $ printbin -b 8 -a 16 -n 5a
        |>  01011010

    Accept input and output binary number;
        $ printbin
            >   333
        |>   00000000 00000000 00000000 00000000 00000000 00000000 00000001 01001101

printbin always prints a base 10 number up to 64 bits, unless the number of bits is set with -b, or the base is set with -a, if base or bits are specified, the number must be proceeded by -n.

Installation (installs to /usr/bin by default):
     
    $ git clone "https://git.huck.website/huboles/printbin.git"
    $ cd printbin
    $ sudo make clean install

