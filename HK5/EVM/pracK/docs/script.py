def matr():

    file = open('data.txt', encoding='utf-8', mode='r')

    alphabet = ['а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л',
                'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш',
                'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я']


    edges = [[0] * 33 for i in range(33)]

    occurences = [0]*33

    for line in file:
        line = line.lower()
        line = line.split('\n')[0]

        if len(line) > 1:
            for i in range(len(line) - 1):
                cur_i = alphabet.index(line[i])
                next_i = alphabet.index(line[i+1])
                edges[cur_i][next_i] += 1

        for i in range(len(alphabet)):
            occurences[i] += line.count(alphabet[i])
    return  occurences , edges

# occur, edges = matr()

# print(edges)
# print(occur)

