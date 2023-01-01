import networkx as nx
import pylab as plt
import matplotlib.pyplot as pllt
import matplotlib
import matplotlib.colors as mcolors
import random

import make_data

occurences, edges = make_data.matr()


elements = ['K','Na','Ca','Ba','Mg','Al','Zn', 'Fe', 'Ni', 'Sn', 'Pb', 'Cu', 'Ag','Hg', 'Pt', 'Au','P',
                'C','O', 'H', 'S', 'N', 'Cl', 'Br', 'I', 'F']

DG = nx.MultiDiGraph()

for ed in range(len(edges)):
    for nod in range(len(edges[ed])):
        if edges[ed][nod] != 0:
            DG.add_weighted_edges_from([(elements[ed], elements[nod], edges[ed][nod])])

for i in range(len(occurences)):
    attrs = {elements[i]: {'weight': occurences[i]}}
    nx.set_node_attributes(DG, attrs)


g = list(DG.nodes.data())
edges_list = list(DG.edges(data=True))

matplotlib.rc('figure', figsize=(50, 50))

color_map = list(mcolors.BASE_COLORS.keys())
color_map.remove('w')
color_map.remove('k')


nx.draw_circular(DG, with_labels=True,
                 width=[w[2]['weight']/100 for w in edges_list],
                 font_size=30,
                 node_size=[list(v)[1]['weight']*100 for v in g],
                 node_color=[random.choice(color_map) for v in g])


pllt.savefig('result.svg')