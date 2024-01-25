import numpy as np

def get_points(maxr,maxc,no_of_points,blim):
    x_cords = np.random.randint(1,maxr,no_of_points)
    y_cords = np.random.randint(1,maxc,no_of_points)
    b_vals = np.random.randint(1,blim,no_of_points)
    return x_cords,y_cords,b_vals


def generate_test(max_points):
    nop = np.random.randint(1,max_points)
    maxr = np.random.randint(1,100000)
    maxc = np.random.randint(1,100000)
    blim = np.random.randint(1,1000000000)
    xs,ys,bs = get_points(maxr,maxc,nop,blim)
    print(f"{maxr} {maxc} {nop}")
    for i in range(0,nop):
        print(f"{xs[i]} {ys[i]} {bs[i]}")



def generate():
    total = 200000
    notc = 10000
    avg = total / notc
    print(notc)
    for i in range(0,notc):
        generate_test(avg)

if __name__ == "__main__":
    generate()
