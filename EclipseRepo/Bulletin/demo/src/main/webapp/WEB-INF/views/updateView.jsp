<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<html>
<head>
<script src="//cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<script type="text/javascript">
	$(document).ready(function() {
		var formObj = $("form[name='updateForm']");

		$(".cancel_btn").on("click", function() {
			event.preventDefault();
			location.href = "/list";
		})

		$(".update_btn").on("click", function() {
			if (fn_valiChk()) {
				return false;
			}
			formObj.attr("action", "/update");
			formObj.attr("method", "post");
			formObj.submit();
		})
	})

	function fn_valiChk() {
		var updateForm = $("form[name='updateForm'] .chk").length;
		for (var i = 0; i < updateForm; i++) {
			if ($(".chk").eq(i).val() == "" || $(".chk").eq(i).val() == null) {
				alert($(".chk").eq(i).attr("subject"));
				return true;
			}
		}
	}
</script>
<title>게시판</title>
</head>
<script type="text/javascript">
	$(document).ready(function() {

		$(".cancel_btn").on("click", function() {
			event.preventDefault();
			location.href = "/list";
		})
	})
</script>
<body>

	<div id="root">
		<header>
			<h1>게시판</h1>
		</header>
		<hr />

		<div>
			<%@include file="nav.jsp"%>
		</div>
		<hr />

		<section id="container">
			<form name="updateForm" role="form" method="post" action="/update">
				<input type="hidden" name="idx" value="${update.idx}"
					readonly="readonly" />
				<table>
					<tbody>
						<tr>
							<td><label for="subject">제목</label><input type="text"
								id="subject" name="subject" value="${update.subject}"
								class="chk" title="제목을 입력하세요." /></td>
						</tr>
						<tr>
							<td><label for="content">내용</label> <textarea id="content"
									name="content" class="chk" title="내용을 입력하세요.">
									<c:out value="${update.content}" />
									</textarea></td>
						</tr>
						<tr>
							<td><label for="writer">작성자</label><input type="text"
								id="writer" name="writer" value="${update.writer}"
								readonly="readonly" /></td>
						</tr>
						<tr>
							<td><label for="regDate">작성날짜</label> <fmt:formatDate
									value="${update.regDate}" pattern="yyyy-MM-dd" /></td>
						</tr>
					</tbody>
				</table>
				<div>
					<button type="submit" class="update_btn">저장</button>
					<button type="submit" class="cancel_btn">취소</button>
				</div>
			</form>
		</section>
		<hr />
	</div>
</body>
</html>