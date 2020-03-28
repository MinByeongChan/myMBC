<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<html>
<head>
	<title>게시판</title>
	<style type="text/css">
		h1{
			font: bold;
			font-style: italic;
			color: #050505;
		}
		li {list-style: none; float: left; padding: 6px}
		
		#table th {
		    border-collapse: collapse;
		    text-align: left;
		    line-height: 1.5;
		    border: 1px solid #ccc;
		    margin: 20px 10px;
		}
		#table thead {
		    border-right: 1px solid #ccc;
		    border-left: 1px solid #ccc;
		    background: #e7708d;
		}
		#table thead th {
		    padding: 10px;
		    font-weight: bold;
		    vertical-align: top;
		    color: #fff;
		}
		#table tbody th {
		    width: 150px;
		    padding: 10px;
		    font-weight: bold;
		    vertical-align: top;
		    border-bottom: 1px solid #ccc;
		    background: #fcf1f4;
		}
		#table td {
		    width: 350px;
		    padding: 10px;
		    vertical-align: top;
		    border-bottom: 1px solid #ccc;
		}
	</style>
</head>
<body>
	<div id="root">
		<header>
			<h1>MBC's 게시판</h1>
		</header>
		<hr />

		<div>
			<%@include file="nav.jsp"%>
		</div>
		<hr />

		<section id="container">
			<form role="form" method="post" action="/write">
				<table id="table">
					<tr>
						<th>번호</th>
						<th>제목</th>
						<th>작성자</th>
						<th>등록일</th>
					</tr>

					<c:forEach items="${list}" var="list">
						<tr>
							<td id="idx"><c:out value="${list.idx}" /></td>
							<td id="subject"><a href="/readView?idx=${list.idx}"><c:out
										value="${list.subject}" /></a></td>
							<td id="writer"><c:out value="${list.writer}" /></td>
							<td id="regDate"><fmt:formatDate value="${list.regDate}"
									pattern="yyyy-MM-dd" /></td>
						</tr>
					</c:forEach>

				</table>
				
			</form>
			
			
		</section>
		<div id="bottom"> 
					<ul>
						<c:if test="${pageMaker.prev}">
							<li><a href="list${pageMaker.makeQuery(pageMaker.startPage - 1)}">이전</a></li>
						</c:if>

						<c:forEach begin="${pageMaker.startPage}"
							end="${pageMaker.endPage}" var="idx">
							<li><a href="list${pageMaker.makeQuery(idx)}">${idx}</a></li>
						</c:forEach>

						<c:if test="${pageMaker.next && pageMaker.endPage > 0}">
							<li><a
								href="list${pageMaker.makeQuery(pageMaker.endPage + 1)}">다음</a></li>
						</c:if>
					</ul>
				</div>
		<hr />
	</div>
</body>
</html>