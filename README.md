# Finding non-binary SNP candidates

The [NCBI](http://www.ncbi.nlm.nih.gov/) has, amongst other things, a public
database of single nucleotide polymorphisms (SNPs).

We have made a tool that searches this database for non-binary SNP candidates
for various purposes. 

## Quickstart
* Make sure the [expat](http://expat.sourceforge.net/) development files and
  libraries are installed.
* Get the program [source](snp.tgz).
* Compile the program. 

To run the program:

* Get one of the files from
  [this](ftp://ftp.ncbi.nih.gov/snp/organisms/human_9606/genotype/) location.
* If we assume that the downloaded file is named **gt_chrXX.xml.gz**, use
  the following command to find the SNP candidates:


      zcat gt_chrXX.xml.gz | ./snp <threshold> > output.txt


The **<treshold>** variable specifies the minimum allele frequency (in
percentages). If this option is omitted, the treshold defaults to 0. By
increasing this variable the amount of output can be greatly reduced, setting
it to 1 or higher is recommended.

Although we have not tested this program on files related to other species, we
see no reason why it should not work. To find input files for other species, go
[here](ftp://ftp.ncbi.nih.gov/snp/organisms/), select one of the directories and
choose the genotype subdirectory (if present).

Of course, when running multiple sessions with different tresholds,
decompressing the downloaded file first and running:


      ./snp <treshold> < gt_chrXX.xml > output.txt

is recommended. 

Inspired by this research, we also looked into a related topic, the degredation
of [methylated nucleotides](https://humgenprojects.lumc.nl/svn/CpG/).
