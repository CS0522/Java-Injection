<%@ page contentType="text/html;charset=UTF-8" language="java" %><%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %><%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %><%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %><%@ taglib uri="http://struts.apache.org/tags-nested" prefix="nested" %>
<%--
    Licensed to the Apache Software Foundation (ASF) under one or more
    contributor license agreements.  See the NOTICE file distributed with
    this work for additional information regarding copyright ownership.
    The ASF licenses this file to You under the Apache License, Version 2.0
    (the "License"); you may not use this file except in compliance with
    the License.  You may obtain a copy of the License at
   
         http://www.apache.org/licenses/LICENSE-2.0
   
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
--%>
<html:html>
  <head>
    <title><bean:message key="lookup.title" /></title>
    <html:base />
  </head>
  <body bgcolor="white">

    <p>
       <html:link forward="module-root"><bean:message key="index.home"/></html:link>
       &nbsp;
       <html:link forward="module-dispatch"><bean:message key="index.title"/></html:link>
    </p>

    <hr />
    <p>
       <strong>Change Language | Changez Le Langage:</strong>
       &nbsp;
       <html:link action="/lookupLocale?language=en">English | Anglais</html:link>
       &nbsp;
       <html:link action="/lookupLocale?language=fr">French | Francais</html:link>
    </p>

    <hr />

  <h3><bean:message key="lookup.title" /></h3>

    <logic:messagesPresent>
      <html:messages id="msg">
          <p><strong><font color="red"><bean:write name="msg" /></font></strong></p>
      </html:messages>
    </logic:messagesPresent>

    <logic:messagesPresent message="true">
      <html:messages message="true" id="msg">
          <p><strong><bean:write name="msg" /></strong></p>
      </html:messages>
    </logic:messagesPresent>

    <logic:messagesNotPresent message="true">
      <logic:messagesNotPresent>
          <p>&nbsp;</p>
      </logic:messagesNotPresent>
    </logic:messagesNotPresent>

       <p>
          <html:form action="lookup-submit" style="display:inline">
              <html:submit property="dispatchParam"><bean:message key="button.foo.label" /></html:submit>
              &nbsp;
              <html:submit property="dispatchParam"><bean:message key="button.bar.label" /></html:submit>
              &nbsp;
              <html:submit property="dispatchParam"><bean:message key="button.invalid.label" /></html:submit>
              &nbsp;
              <html:submit property="wrongParam"><bean:message key="parameter.wrong.label" /></html:submit>
          </html:form>
          <html:form action="lookup-noparam" style="display:inline">
              &nbsp;
              <html:submit property="dispatchParam"><bean:message key="parameter.missing.label" /></html:submit>
          </html:form>
       </p>

  </body>
</html:html>
