v<int> merge(v<int> &v1, v<int> &v2)
{
    int i = 0, j = 0;

    // Final vector to return
    // after merging
    v<int> v;

    // Loop continues until it reaches
    // the end of one of the vectors
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j])
        {
            v.push_back(v1[i]);
            i++;
        }
        else
        {
            v.push_back(v2[j]);
            j++;
        }
    }

    // Here, simply add the remaining
    // elements to the vector v
    for (int k = i; k < v1.size(); k++)
        v.push_back(v1[k]);
    for (int k = j; k < v2.size(); k++)
        v.push_back(v2[k]);
    return v;
}

void buildTree(v<v<int>> &tree, v<int> &arr, int index, int s, int e)
{
    if (s > e)
        return;

    if (s == e)
    {
        tree[index].push_back(arr[s]);
        return;
    }

    int mid = (s + e) / 2;
    buildTree(tree, arr, 2 * index, s, mid);
    buildTree(tree, arr, 2 * index + 1, mid + 1, e);

    v<int> left = tree[2 * index];
    v<int> right = tree[2 * index + 1];

    tree[index] = merge(left, right);
    return;
}

int query(v<v<int>> &tree, int index, int s, int e, int qs, int qe, int k)
{
    if (s > qe or e < qs) //No Overlap
        return 0;

    if (s >= qs and e <= qe) //complete overlap
    {
        auto curr = tree[index];
        return curr.size() - (lower_bound(curr.b(), curr.e(), k + 1) - curr.b());
    }

    int mid = (s + e) / 2; //partial overlap
    int left = query(tree, 2 * index, s, mid, qs, qe, k);
    int right = query(tree, 2 * index + 1, mid + 1, e, qs, qe, k);

    return (left + right);
}
