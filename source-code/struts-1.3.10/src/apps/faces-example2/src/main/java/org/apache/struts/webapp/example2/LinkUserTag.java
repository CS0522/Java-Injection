/*
 * $Id: LinkUserTag.java 471754 2006-11-06 14:55:09Z husted $
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */


package org.apache.struts.webapp.example2;


import java.io.IOException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;
import org.apache.struts.util.MessageResources;
import org.apache.struts.util.ResponseUtils;


/**
 * Generate a URL-encoded hyperlink to the specified URI, with
 * associated query parameters selecting a specified User.
 *
 * @author Craig R. McClanahan
 * @version $Rev: 471754 $ $Date: 2006-11-06 08:55:09 -0600 (Mon, 06 Nov 2006) $
 */

public class LinkUserTag extends TagSupport {


    // ------------------------------------------------------ Instance Variables


    /**
     * The hyperlink URI.
     */
    protected String page = null;


    /**
     * The message resources for this package.
     */
    protected static MessageResources messages =
    MessageResources.getMessageResources
    ("org.apache.struts.webapp.example.ApplicationResources");


    /**
     * The attribute name.
     */
    private String name = "user";


    // ------------------------------------------------------------- Properties


    /**
     * Return the hyperlink URI.
     */
    public String getPage() {

    return (this.page);

    }


    /**
     * Set the hyperlink URI.
     *
     * @param page Set the hyperlink URI
     */
    public void setPage(String page) {

    this.page = page;

    }


    /**
     * Return the attribute name.
     */
    public String getName() {

    return (this.name);

    }


    /**
     * Set the attribute name.
     *
     * @param name The new attribute name
     */
    public void setName(String name) {

    this.name = name;

    }


    // --------------------------------------------------------- Public Methods


    /**
     * Render the beginning of the hyperlink.
     *
     * @exception JspException if a JSP exception has occurred
     */
    public int doStartTag() throws JspException {

    // Generate the URL to be encoded
        HttpServletRequest request =
            (HttpServletRequest) pageContext.getRequest();
        StringBuffer url = new StringBuffer(request.getContextPath());
        url.append(page);
    User user = null;
    try {
        user = (User) pageContext.findAttribute(name);
        } catch (ClassCastException e) {
        user = null;
    }
    if (user == null)
        throw new JspException
            (messages.getMessage("linkUser.noUser", name));
    if (page.indexOf("?") < 0)
        url.append("?");
    else
        url.append("&");
    url.append("username=");
    url.append(ResponseUtils.filter(user.getUsername()));

    // Generate the hyperlink start element
    HttpServletResponse response =
      (HttpServletResponse) pageContext.getResponse();
    StringBuffer results = new StringBuffer("<a href=\"");
    results.append(response.encodeURL(url.toString()));
    results.append("\">");

    // Print this element to our output writer
    JspWriter writer = pageContext.getOut();
    try {
        writer.print(results.toString());
    } catch (IOException e) {
        throw new JspException
        (messages.getMessage("linkUser.io", e.toString()));
    }

    // Evaluate the body of this tag
    return (EVAL_BODY_INCLUDE);

    }



    /**
     * Render the end of the hyperlink.
     *
     * @exception JspException if a JSP exception has occurred
     */
    public int doEndTag() throws JspException {


    // Print the ending element to our output writer
    JspWriter writer = pageContext.getOut();
    try {
        writer.print("</a>");
    } catch (IOException e) {
        throw new JspException
            (messages.getMessage("link.io", e.toString()));
    }

    return (EVAL_PAGE);

    }


    /**
     * Release any acquired resources.
     */
    public void release() {

        super.release();
        this.page = null;
        this.name = "user";

    }


}
