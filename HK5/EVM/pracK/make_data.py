
# K, Na, Ca, Ba, Mg, Al, Zn, Fe, Ni, Sn, Pb, Cu, Ag, Hg, Pt, Au
# C, O, H, S, P, N, Cl, Br, I, F.
NUM_ELEMS = 26

def matr():
    file = open('data.txt', encoding='utf-8', mode='r')

    elements = ['K','Na','Ca','Ba','Mg','Al','Zn', 'Fe', 'Ni', 'Sn', 'Pb', 'Cu', 'Ag','Hg', 'Pt', 'Au','P',
                'C','O', 'H', 'S', 'N', 'Cl', 'Br', 'I', 'F']

    edges = [[0] * NUM_ELEMS for i in range(NUM_ELEMS)]
    occurences = [0]*NUM_ELEMS

    for line in file:
        for molecule in line.split():
            arr = []
            for i in range(len(molecule)):
                if not molecule[i].isdigit():
                    if molecule[i] in ['(', ')'] : continue
                    if molecule[i].isupper():
                        arr.append(molecule[i])
                    elif molecule[i].islower():
                        if len(arr) > 0: arr[len(arr)-1] += molecule[i]
            if len(arr) > 1:
                for i in range(len(arr) - 1):
                    cur_i = elements.index(arr[i])
                    next_i = elements.index(arr[i+1])
                    edges[cur_i][next_i] += 1
            # elif len(arr) == 1:
            #     for i in range(molecule):
            #         if molecule[i].isdigit:
            #             cur_i = elements.index(arr[0])
            #             edges[cur_i][cur_i] += 1

            for i in range(len(elements)):
                occurences[i] += molecule.count(elements[i])
    return  occurences , edges

# occur, edges = matr()
# print(edges)
# print(occur)
