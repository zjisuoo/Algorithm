def gomgomi(n):
    gomgom = set()
    cnt = 0
    for _ in range(n):
        word = input()

        if word != 'ENTER':
            if word not in gomgom:
                cnt += 1
                gomgom.add(word)
        elif word == 'ENTER':
            gomgom.clear()

    return cnt

print(gomgomi(int(input())))