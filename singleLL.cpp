ListAppend(list, newNode) {
   if (list⇢head == null) { // List empty
      list⇢head = newNode
      list⇢tail = newNode
   }
   else{
      list⇢tail⇢next = newNode
      list⇢tail = newNode
   }
}

ListPrepend(list, newNode) {
   if (list⇢head == null) { // list empty
      list⇢head = newNode
      list⇢tail = newNode
   }
   else {
      newNode⇢next = list⇢head
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
      list⇢tail = newNode
   }
   else {
      newNode⇢next = curNode⇢next
      curNode⇢next = newNode
   }
}

ListRemoveAfter(list, curNode) {
   // Special case, remove head
   if (curNode is null && list⇢head is not null) {
      sucNode = list⇢head⇢next
      list⇢head = sucNode

      if (sucNode is null) { // Removed last item
         list⇢tail = null
      }
   }
   else if (curNode⇢next is not null) {
      sucNode = curNode⇢next⇢next
      curNode⇢next = sucNode

      if (sucNode is null) { // Removed tail
         list⇢tail = curNode
      }
   }
}

ListInsertionSortSinglyLinked(list) {
   beforeCurrent = list⇢head
   curNode = list⇢head⇢next
   while (curNode != null) {
      next = curNode⇢next
      position = ListFindInsertionPosition(list, curNode⇢data)

      if (position == beforeCurrent)
         beforeCurrent = curNode
      else {
         ListRemoveAfter(list, beforeCurrent)
         if (position == null)
            ListPrepend(list, curNode)
         else
            ListInsertAfter(list, position, curNode)
      }

      curNode = next
   }
}
ListFindInsertionPosition(list, dataValue) {
   curNodeA = null
   curNodeB = list⇢head
   while (curNodeB != null and dataValue > curNodeB⇢data) {
      curNodeA = curNodeB
      curNodeB = curNodeB⇢next
   }
   return curNodeA
}
