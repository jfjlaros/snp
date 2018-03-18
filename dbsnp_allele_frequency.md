# Allele frequency correction for chromosomes X and Y
For some variants (notably on chromosome X and Y), SNP reports contain allele
'0' to indicate that a variant is found in a hemizygous state. While this is
correct when reporting a genotype, for allele frequencies, this is problematic.

The formula to convert between these different ways of calculating the allele
frequencies is as follows:

    r(X) = o(X) / (1 - o(0)),

where r is the real allele frequency of X and o is the observed allele
frequency of X.


## Example: biallelic SNP
We start with a given allele frequency:

    A: 0.8
    G: 0.2

This results in the following genotype frequencies:

      F:        M:
    AA: 0.64  A0: 0.8
    AG: 0.32  G0: 0.2
    GG: 0.04

And if we mix the populations, the genotype frequencies become:

      M:F = 1:2
    AA: 0.64 * 0.67 = 0.4288
    AG: 0.32 * 0.67 = 0.2144
    GG: 0.04 * 0.67 = 0.0268
    A0: 0.8  * 0.33 = 0.2640
    G0: 0.2  * 0.33 = 0.0660

The observed allele frequencies (o) are now:

    A: (0.4288 * 2 + 0.2144 + 0.2640) / 2 = 0.6680
    G: (0.0268 * 2 + 0.0268 + 0.0660) / 2 = 0.1670
    0:              (0.2640 + 0.0660) / 2 = 0.1650

The fraction of males is: 2 * o(0).

To calculate the real allele frequencies: r(X) = o(X) / (1 - o(0))

    r(A) = 0.6680 / (1 - 0.1650) = 0.8
    r(G) = 0.1670 / (1 - 0.1650) = 0.2


## Example: triallelic SNP
We start with a given allele frequency:

    A: 0.7
    G: 0.2
    T: 0.1

This results in the following genotype frequencies:

      F:        M:
    AA: 0.49  A0: 0.7
    AG: 0.28  G0: 0.2
    AT: 0.14  T0: 0.1
    GG: 0.04
    GT: 0.04
    TT: 0.01

And if we mix the populations, the genotype frequencies become:

      M:F = 1:2
    AA: 0.49 * 0.67 = 0.3283
    AG: 0.28 * 0.67 = 0.1876
    AT: 0.14 * 0.67 = 0.0938
    GG: 0.04 * 0.67 = 0.0268
    GT: 0.04 * 0.67 = 0.0268
    TT: 0.01 * 0.67 = 0.0067
    A0: 0.7  * 0.33 = 0.2310
    G0: 0.2  * 0.33 = 0.0660
    T0: 0.1  * 0.33 = 0.0330

The observed allele frequencies (o) are now:

    A: (0.3283 * 2 + 0.1876 + 0.0938 + 0.2310) / 2 = 0.5845
    G: (0.0268 * 2 + 0.1876 + 0.0268 + 0.0660) / 2 = 0.1670
    T: (0.0067 * 2 + 0.0938 + 0.0268 + 0.0330) / 2 = 0.0835
    0:              (0.2310 + 0.0660 + 0.0330) / 2 = 0.1650

The fraction of males is: 2 * o(0).

To calculate the real allele frequencies: r(X) = o(X) / (1 - o(0))

    r(A) = 0.5845 / (1 - 0.1650) = 0.7
    r(G) = 0.1670 / (1 - 0.1650) = 0.2
    r(T) = 0.0835 / (1 - 0.1650) = 0.1
