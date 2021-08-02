package Algorithm.datastructure;

public class LinkedList {
    public class ListNode {
        private String data;
        public ListNode link;

        public ListNode() {
            this.data = null;
            this.link = null;
        }

        public ListNode(String data) {
            this.data = data;
            this.link = null;
        }

        public ListNode(String data, ListNode link) {
            this.data = data;
            this.link = link;
        }

        public String getData() {
            return this.data;
        }

    }

    private ListNode head;

    public LinkedList() {
        head = null;
    }

    public void insertNode(ListNode preNode, String data) {
        ListNode newNode = new ListNode(data);

        newNode.link = preNode.link;
        preNode.link = newNode;
    }

    public void insertNode(String data) {
        ListNode newNode = new ListNode(data);

        if(head == null) {
            this.head = newNode;
        } else {
            ListNode tempNode = head;
            while(tempNode.link != null) {
                tempNode = tempNode.link;    // 다음 노드를 참조
            }

            tempNode.link = newNode;
        }
    }

    public void deleteNode(String data) {
        ListNode prevNode = head;
        ListNode tempNode = head.link;

        if(data.equals(prevNode.getData())) {
            head = prevNode.link;
            prevNode.link = null;
        } else {
            while(tempNode != null) {
                if(data.equals(tempNode.getData())) {
                    if(tempNode.link == null) {
                        prevNode.link = null;
                    } else {
                        prevNode.link = tempNode.link;
                        tempNode.link = null;
                    }
                    break;
                } else {
                    prevNode = tempNode;
                    tempNode = tempNode.link;
                }
            }
        }
    }

    public void printList() {
        ListNode tempNode = new ListNode();

        while(tempNode != null) {
            System.out.println(tempNode.getData()+ " ");
            tempNode = tempNode.link;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.insertNode("sun");
        list.insertNode("mon");
        list.insertNode("tue");
        list.insertNode("wed");

        list.printList();

    }
}