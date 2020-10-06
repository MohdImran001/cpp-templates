void buildTree(v<int> &tree, v<int> &arr, int index, int s, int e)
{
    if (s > e)
        return;

    if (s == e)
    {
        tree[index] = arr[s];
        return;
    }

    int mid = (s + e) / 2;
    buildTree(tree, arr, 2 * index, s, mid);
    buildTree(tree, arr, 2 * index + 1, mid + 1, e);

    int left = tree[2 * index];
    int right = tree[2 * index + 1];

    tree[index] = min(left, right);
    return;
}

int query(v<int> &tree, int index, int s, int e, int qs, int qe)
{
    if (s > qe or e < qs) //No Overlap
        return INT_MAX;

    if (s >= qs and e <= qe) //complete overlap
        return tree[index];

    int mid = (s + e) / 2; //partial overlap
    int left = query(tree, 2 * index, s, mid, qs, qe);
    int right = query(tree, 2 * index + 1, mid + 1, e, qs, qe);

    return min(left, right);
}

void update(v<int> &tree, int index, int s, int e, int i, int val)
{
    if (i < s or i > e)
        return;

    if (s == e)
    {
        tree[index] = val;
        return;
    }

    int mid = (s + e) / 2;
    update(tree, 2 * index, s, mid, i, val);
    update(tree, 2 * index + 1, mid + 1, e, i, val);

    int left = tree[2 * index];
    int right = tree[2 * index + 1];
    tree[index] = min(left, right);
    return;
}

void updateRange(v<int> &tree, int index, int s, int e, int qs, int qe, int val)
{
    if (qe < s or qs > e)
        return;

    if (s == e)
    {
        tree[index] += val;
        return;
    }

    int mid = (s + e) / 2;
    updateRange(tree, 2 * index, s, mid, qs, qe, val);
    updateRange(tree, 2 * index + 1, mid + 1, e, qs, qe, val);

    int left = tree[2 * index];
    int right = tree[2 * index + 1];
    tree[index] = min(left, right);
    return;
}
