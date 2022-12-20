# *base* - CLI utility to convert numbers between arbitrary bases.

*base* converts from base 10 to binary if called with no options. Input and output base can be specified with -i and -o respectively, ranging from 2-62. If no number is given, base will prompt for a number, or convert stdin if given.
If not specified, base will print binary numbers as unsigned longs with 64 bits, hexadecimal numbers with a leading 0x, octal  and any other number with no leading zeroes. Truncation/leading zeroes can be specified with -l and -L, giving the number of digits from the lowest or highest number, respectively. 

## Usage:

- Print binary representation:

        $ base 555
        00000000 00000000 00000000 00000000 00000000 00000000 00000010 00101011
    
- Print a number in hexadecimal:

        $ base -o 16 1234
        0x4d2

- Print an octal representation of a base 12 number

        $ base -o 8 -i 12 5a
        106

- Convert stdin to base 8

        $ echo "123456" | base -o 8

        361100

## Installation :

- Download .zip or .tar.gz and decompress

        $ unzip base-{branch}.zip 

    ***OR***

        $ tar -I gzip -cvf base-{branch}.tar.gz
     
- Build base from source
    
        $ cd base-{branch}
        $ sudo make install

