# Finding non-biallelic SNPs
SNPs are used as markers for various population genetic purposes. In particular
non-biallelic SNPs are of interest for identification purposes; to have the
same discriminative power, more biallelic than non-biallelic SNPs are required.

In this project, we present a tool that uses the
[NCBI](http://www.ncbi.nlm.nih.gov/) a public database
[dbSNP](https://www.ncbi.nlm.nih.gov/projects/SNP/) to identify non-biallelic
SNPs.

This work was [published](https://www.ncbi.nlm.nih.gov/pubmed/19647708) in
[FSI Genetics](http://www.fsigenetics.com/) in 2009.


## Installation
Install the [expat](http://expat.sourceforge.net/) development files:

    apt-get install libexpat1-dev

Compile the program:

    make


## Usage
The program requires a dump of the database in XML format. These files are
typically found in the subfolder named `genotype` of any of the builds hosted
on the [download site](ftp://ftp.ncbi.nih.gov/snp/organisms/) of the NCBI.

For a file named `gt_chrXX.xml.gz`, use the following command to find the SNP
candidates:

      zcat gt_chrXX.xml.gz | ./snp <threshold> > output.txt

The `treshold` parameter is used to specify the minimum allele frequency (in
percentages). If this option is omitted, the threshold defaults to 0. By
increasing this variable the amount of output can be greatly reduced, setting
it to 1 or higher is recommended.


## Related work
Some [notes](dbsnp_allele_frequency.md) on allele frequencies on the X- and
Y chromosomes.

Inspired by this research, we looked into the degradation of
[methylated nucleotides](https://github.com/jfjlaros/cpg) for similar purposes.
