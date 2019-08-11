from itertools import combinations

def refactor_print(pairs):
    if len(pairs) > 1:
        for size in range(len(pairs),0,-1):
            for comb in combinations(pairs,size):
                if(valid_pairs(comb)):
                    left = set(pairs)-set(comb)
                    if len(left) > 0:
                        return [[comb],*refactor_print(left)]
                    else:
                        return [[comb]]
    return [pairs]

def valid_pairs(pairs):
    all_values = []
    for pair in pairs:
        all_values.extend(pair)
    return len(all_values) == len(set(all_values))

def n_sum(n):
    return (n+1)*n//2

def sort(fro,to):
    if(fro < to):
        mid = (fro+to)>>1
        output = 0
        output+=sort(fro,mid)
        output+=sort(mid+1,to)
        if(fro+1==to):
            print(f'1 {fro} {to}')
            return output+1
        else:
            pairs = []
            for i in range(fro,mid+1):
                for j in range(mid+i,to+1):
                    pairs.append((i,j))
            length = 0
            for pair_go in refactor_print(pairs):
                length+=1
                print(f'{len(pair_go)} {" ".join(map(lambda pair:" ".join(map(str,pair)),pairs))}')
            return output+length
    return 0

if __name__ == '__main__':
    numBoxs = int(input(''))
    print(sort(1,numBoxs))