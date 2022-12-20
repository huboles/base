# *base* - CLI utility to convert numbers between arbitrary bases.

*base* 

## Usage:

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

        361100

## Installation :

- Download .zip or .tar.gz and decompress

        $ unzip base-{branch}.zip 

    OR 

        $ tar -I gzip -cvf base-{branch}.tar.gz
     
- Build base from source
    
        $ cd base-{branch}

        $ sudo make install

