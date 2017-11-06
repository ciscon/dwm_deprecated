void
reapplyrules(const Arg *arg) {
    Monitor *m;
    size_t i;

    for (m = mons; m; m = m->next)
        while (m->stack)
            unmanage(m->stack, 0);
    while (mons)
        cleanupmon(mons);

    setup();
    scan();
}
