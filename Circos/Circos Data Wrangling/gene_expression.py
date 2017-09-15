# This script functions to take in the gene expression values from cuffdiff,
# assign them to chromosomes using data from cuffmerge, and finally to produce 
# an expression file that can be plotted in Circos

import re
import pandas as pd
import numpy as np

# Reading in expression values
pipeline_expression = pd.read_table("~/Documents/Teleogene/RAT_EXPERIMENT/results/tuxedo_pipeline/cuffdiff_treatment_0.control_0/gene_exp.diff", sep="\s+")

# Associates each gene with each chromosome
chr_association = pd.read_table("~/Documents/Teleogene/RAT_EXPERIMENT/results/tuxedo_pipeline/cuffmerge_treatment_0.control_0/merged.gtf", sep="\s+", usecols=[0,9], header=None)
chr_association[9] = chr_association[9].map(lambda x: x.rstrip(';'))

def strip_start_stop(locus,location):
    m = re.search(r"\:([0-9]+)\-([0-9]+)$",locus)
    if m:
        track = [m.group(1),m.group(2)]
    return(track[location])

# Restricting datasets to necessary columns
pipeline_expression = pipeline_expression[['gene_id','gene','log2(fold_change)','locus']]
chr_association.columns = ['chromosome','gene_id']

# Merging the two datasets
# This allows each value to be associated with a certain locus on a certain chromosome
merged = pd.merge(pipeline_expression, chr_association, how='left', on='gene_id')

# Removing abnormal naming convention
chr_filter = merged['chromosome'].str.contains("^chr[0-9]+$")
merged = merged[chr_filter]

# Merging the dataframes created a lot of duplicate entries
merged = merged.drop_duplicates()

# Experimentat results were poor, so I am generating some random values
# values are on the exponential scale to more closely reflect normal expression values
merged['log2(fold_change)'] = merged['log2(fold_change)'].map( lambda x: int(np.exp(np.random.uniform(0,10))))

# Separating the gene locus into start and stop values (Circos requirement)
merged['start'] = merged['locus'].apply(strip_start_stop, args=(0,))
merged['stop'] = merged['locus'].apply(strip_start_stop, args=(1,))

# Removing unecessary columns
merged = merged.drop(['locus','gene_id'], axis=1)

# Formatting to match Circos requirements
merged['chromosome'] = merged['chromosome'].map(lambda x: "Rn6.{:02d}".format(int(x.lstrip('chr'))))
merged['gene'] = 'gene=' + merged['chromosome'] + "." + merged['gene'].map(lambda x: re.sub(r'\,.*', '', x))
merged = merged[['chromosome', 'start', 'stop', 'log2(fold_change)', 'gene']]

# Resetting the index of out newly completed dataframe
merged = merged.reset_index(drop=True)

#  Writing our the dataframe as a text file for use in Circos
np.savetxt('/Users/neilklenk/Documents/Teleogene/Circos/Circos Data Wrangling/gene_expression_randval.txt', merged.values, fmt='%s')
