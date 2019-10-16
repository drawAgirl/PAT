
int n;
const int MAXN = 30;
int data[MAXN];
typedef struct node{
    int v,height;
    node *left,*right;
}Node,*TreeNode;


TreeNode newNode(int v){
    TreeNode node = new Node;
    node->v = v;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

int getHeight(TreeNode root){
    if(root == NULL) return 0;
    return root->height;
}

int getBalanceFactor(TreeNode root){
    return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(TreeNode root){
    root->height = max(getHeight(root->left), getHeight(root->right))+1;
}

void L(TreeNode &root){
    TreeNode temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(TreeNode &root){
    TreeNode temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(TreeNode &root,int v){
    if(!root){
        root = newNode(v);
        return;
    }
    if(v < root->v){
        insert(root->left, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->left) == 1){
                R(root);
            }else if(getBalanceFactor(root->left) == -1){
                L(root->left);
                R(root);
            }
        }
    }else{
        insert(root->right, v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->right) == -1){
                L(root);
            }else if(getBalanceFactor(root->right) == 1){
                R(root->right);
                L(root);
            }
        }
    }
}

queue<TreeNode> q;
int space = 0;
void level(TreeNode root){
    if(!root)
        return ;
    q.push(root);
    while(!q.empty()){
        TreeNode temp = q.front();
        q.pop();
        space++;
        printf("%d",temp->v);
        if(space < n)
            printf(" ");
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    printf("\n");
}
bool istree(TreeNode root){
    queue<TreeNode> q;
    q.push(root);
    TreeNode p;
    while ((p= q.front()) != NULL ) {
        q.push(p->left);
        q.push(p->right);
        q.pop();
    }
    while (!q.empty()) {
        if (q.front()) {
            return false;
        }
        q.pop();
    }
    return true;
    
}

int main(){
    scanf("%d",&n);
    TreeNode root = NULL;
    for(int i=0;i<n;i++){
        int v;
        scanf("%d",&v);
        insert(root, v);
    }
    level(root);
    bool flag = istree(root);
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
}
