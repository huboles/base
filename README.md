# *base* - CLI utility to convert numbers between arbitrary bases.


Usage:

- Print binary representation:

        $ base 555

        00000000 00000000 00000000 00000000 00000000 00000000 00000010 00101011
    
- Print a number in base 16:

        $ base -o 16  1234

        0x4d2

- Print an base 8 representation of a base 12 number

        $ base -o 8 -i 16 5a

        106

- Call without an input number to convert stdin

        $ echo "123456" | base -o 8


Installation (installs to /usr/bin by default):

    Download .zip or .tar.gz
     
    $ cd base
    $ sudo make install

