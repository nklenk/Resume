# Chromosome lengths from http://genome.ucsc.edu/cgi-bin/hgTracks?db=rn6&chromInfoPage=

chr_len_dict = {'chr1': 282763074, 'chr2': 266435125, 'chr3': 184226339,
                'chr4': 177699992,'chr5': 173707219, 'chr6': 147991367,
                'chr7': 145729302, 'chr8': 133307652,'chr9': 122095297,
                'chr10': 112626471, 'chr11': 90463843, 'chr12': 52716770,
                'chr13': 114033958, 'chr14': 115493446, 'chr15': 111246239,
                'chr16': 90668790, 'chr17': 90843779, 'chr18': 88201929,
                'chr19': 62275575, 'chr20': 56205956, 'chr21': 159970021,
                'chr22': 3310458}

with open('Rn6.karyotype.txt', 'w') as f:
    for i, key in enumerate(chr_len_dict.keys()):
        f.writelines("chr - Rn6.{:02d} {:02d} 0 {} Rn6.{:02d}\n".format(i+1,i+1,chr_len_dict[key], i+1))
