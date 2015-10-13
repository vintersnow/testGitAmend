
struct que_commit
{
  struct commit *commit;
  struct que_commit *next;
};

void push_que(struct commit *c,struct que_commit *end){
  struct que_commit *n = (struct que_commit*)xmalloc(sizeof(struct commit));
  n->commit = c;
  n->next = NULL;
  end->next =n
  end = n;
}

struct commit* pop_que(struct que_commit *head){
  struct commit *c = head->commit;
  head = head->next;
  return c;
}


int breadth_search_commit(struct commit *ci,struct commit *target){
  struct que_commit *head,*end;
  push_que(ci,end);
  head = end;
  struct commit_list *list = ci->parents;
  struct commit *item,;
  while(1){
    while((item=list->item)){
      push_que(item,end);
      list = list->next;
    }

    if (strcmp(target->object->sha1,ci->object->sha1)==0){
      return move;
    }
    // new_ci = new_ci->parents
  }
}

int not_pushed(struct commit *current_head){
  struct commit *remote_head;
  unsigned char sha1[20];
  const struct name_decoration decoration;
  int decoration_style=1;
  if (decoration_style) {
    load_ref_decorations(decoration_style);
  }

  decoration = get_name_decoration(&current_head->object);
  const char* upstream = (branch_get(NULL)->merge)?branch_get(NULL)->merge[0]->dst : NULL;
  if (upstream==NULL)
    return (int)true;

  if (get_sha1(upstream, sha1))
    remote_head = NULL;
  else {
    remote_head = lookup_commit_or_die(sha1, upstream);
    if (parse_commit(remote_head))
      die(_("could not parse remote head commit"));
  }

  struct commit *old_ci=remote_head,*new_ci=current_head;
  if (old_ci->date > new_ci->date){
    struct commit *tmp = old_ci;
    old_ci=new_ci;
    new_ci=tmp;
  }

}
