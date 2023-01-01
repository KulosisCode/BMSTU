import networkx as nx
import pylab as plt
import matplotlib.pyplot as pllt
import matplotlib
import matplotlib.colors as mcolors
import random

import script

occurences, edges = script.matr()

# цвет вершины - от белого до черного, размер от какого-то маленького, до
# умеренно большого, соответственно, чем больше вес, тем "черней" (прибавляем
# какое-то значение к rgb коду) и больше размер

# цвет ребра - аналогично, ширина - аналогично.

alphabet = ['а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л',
            'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш',
            'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я']

DG = nx.MultiDiGraph()

for ed in range(len(edges)):
    for nod in range(len(edges[ed])):
        if edges[ed][nod] != 0:
            DG.add_weighted_edges_from([(alphabet[ed], alphabet[nod], edges[ed][nod])])

for i in range(len(occurences)):
    attrs = {alphabet[i]: {'weight': occurences[i]}}
    nx.set_node_attributes(DG, attrs)


g = list(DG.nodes.data())
edges_list = list(DG.edges(data=True))

matplotlib.rc('figure', figsize=(50, 50))

color_map = list(mcolors.BASE_COLORS.keys())
color_map.remove('k')

nx.draw_circular(DG, with_labels=True,
                 width=[w[2]['weight']/1000 for w in edges_list],
                 font_size=30,
                 node_size=[list(v)[1]['weight']*2.5 for v in g],
                 node_color=[random.choice(color_map) for v in g])


pllt.savefig('labels.svg')

# print(list(mcolors.BASE_COLORS.keys()))
# print(random.choice(list(mcolors.BASE_COLORS.keys())))

#  color=[random.choice(color_map) for v in g.values()]