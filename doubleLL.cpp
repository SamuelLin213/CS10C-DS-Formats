ListAppend(list, newNode) {
   if (list⇢head == null) { // List empty
      list⇢head = newNode
      list⇢tail = newNode
   }
   else {
      list⇢tail⇢next = newNode
      newNode⇢prev = list⇢tail
      list⇢tail = newNode
   }
}

ListPrepend(list, newNode) {
   if (list⇢head == null) { // List empty
      list⇢head = newNode
      list⇢tail = newNode
   }
   else {
      newNode⇢next = list⇢head
      list⇢head⇢prev = newNode
      list⇢head = newNode
   }
}

ListInsertAfter(list, curNode, newNode) {
   if (list⇢head == null) { // List empty
      list⇢head = newNode
      list⇢tail = newNode
   }
   else if (curNode == list⇢tail) { // Insert after tail
      list⇢tail⇢next = newNode
      newNode⇢prev = list⇢tail
      list⇢tail = newNode
   }
   else {
      sucNode = curNode⇢next
      newNode⇢next = sucNode
      newNode⇢prev = curNode
      curNode⇢next = newNode
      sucNode⇢prev = newNode
   }
}

ListRemove(list, curNode) {
   sucNode = curNode⇢next
   predNode = curNode⇢prev

   if (sucNode is not null) {
      sucNode⇢prev = predNode
   }

   if (predNode is not null) {
      predNode⇢next = sucNode
   }

   if (curNode == list⇢head) { // Removed head
      list⇢head = sucNode
   }

   if (curNode == list⇢tail) { // Removed tail
      list⇢tail = predNode
   }
}

ListInsertionSortDoublyLinked(list) {
   curNode = list⇢head⇢next
   while (curNode != null) {
      nextNode = curNode⇢next
      searchNode = curNode⇢prev
      while (searchNode != null and searchNode⇢data > curNode⇢data) {
         searchNode = searchNode⇢prev
      }
      // Remove and re-insert curNode
      ListRemove(list, curNode)
      if (searchNode == null) {
         curNode⇢prev = null
         ListPrepend(list, curNode)
      }
      else {
         ListInsertAfter(list, searchNode, curNode)
      }
      // Advance to next node
      curNode = nextNode
   }
}
