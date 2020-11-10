const ll MAX = 1e5 + 1;
vector<ll> parent(MAX);
vector<ll> size(MAX, 1);

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}

ll find_set(ll v)
{
    if (parent[v] == v)
        return v;

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    if (size[a] < size[b])
        swap(a, b);
    parent[b] = a;
    size[a] += size[b];
}
