from operator import itemgetter
class node:
    def __init__(self,id,parents=None,children=None,number_of_estate=0,area_of_estate=0):
        self.id = id
        if type(parents) == int:
            parents_list = [parents]
            self.parents = parents_list
        else:
            self.parents = parents
        if type(children) == int:
            children_list = [children]
            self.children = children_list
        else:
            self.children = children
        self.number_of_estate = number_of_estate
        self.area_of_estate = area_of_estate

    def add_parents(self,parent):
        if self.parents is None:
            self.parents = []
        self.parents.append(parent)

    def add_child(self,child):
        if self.children is None:
            self.children = []
        self.children.append(child)

    def set_both(self,number,area):
        self.number_of_estate = number
        self.area_of_estate = area

n=int(input())
id_list = []
tree = {}
for _ in range(n):
    id,father,mother,k,*children,number_of_estate,area_of_estate = map(int,input().split())
    id_list.append(id)
    if tree.get(id) is None:
        tree[id] = node(id,[father,mother],children,number_of_estate,area_of_estate)
    else:
        tree[id].set_both(number_of_estate,area_of_estate)
        for child in children:
            tree[id].add_child(child)
        if father:
            tree[id].add_parents(father)
        if mother:
            tree[id].add_parents(mother)
    if father:
        if tree.get(father) is None:
            tree[father] = node(father, children=id)
        else:
            tree[father].add_child(id)
    if mother:
        if tree.get(mother) is None:
            tree[mother] = node(mother,children=id)
        else:
            tree[mother].add_child(id)
    for child in children:
        if tree.get(child) is None:
            tree[child] = node(child,parents=id)
        else:
            tree[child].add_parents(id)
vis ={i:False for i,j in tree.items()}
def dfs(id):
    global cur_total_areas,cur_total_members,cur_total_estate,small_root
    if id == -1 or vis[id]:
        return
    vis[id] = True
    small_root = min(small_root,id)
    cur_total_members += 1
    cur_total_estate += tree[id].number_of_estate
    cur_total_areas += tree[id].area_of_estate
    if tree[id].parents is not None:
        for each in tree[id].parents:
            if each == -1:
                continue
            dfs(each)
    if tree[id].children is not None:
        for each in tree[id].children:
            if each == -1:
                continue
            dfs(each)
ans = []
for id in id_list:
    cur_total_members = 0
    cur_total_areas = 0
    cur_total_estate = 0
    small_root = 1e9
    if vis[id] == False:
        dfs(id)
        ans.append((small_root,cur_total_members,cur_total_estate/cur_total_members,-cur_total_areas/cur_total_members))
ans.sort(key=itemgetter(3,0))
print(len(ans))
for each in ans:
    print("%04d %d %.3f %.3f"%(each[0],each[1],each[2],-each[3]))