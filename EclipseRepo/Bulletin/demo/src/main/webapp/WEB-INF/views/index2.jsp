<%@page import="java.util.Map"%>
<%@page import="java.util.HashMap"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>


</head>
<body>

<%
	List<Map<String, String>> results = (List<Map<String, String>>) request.getAttribute("allBoard");
	for (Map<String, String> allBoard : results) {
		String subject = allBoard.get("subject");
		out.println("subject : " + subject+"\n");

		String writer = allBoard.get("writer");
		out.println("writer : " + writer+"\n");

		String content = allBoard.get("content");
		out.println("content : " + content+"\n");

		String idx = String.valueOf(allBoard.get("idx"));
		out.println("idx : " + idx+"\n");
	}
	
%>
</body>
</html>