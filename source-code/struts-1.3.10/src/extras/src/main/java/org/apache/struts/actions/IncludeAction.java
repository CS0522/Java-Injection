/*
 * $Id: IncludeAction.java 471754 2006-11-06 14:55:09Z husted $
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
package org.apache.struts.actions;

import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * <p>An <strong>Action</strong> that includes the context-relative URI
 * specified by the <code>parameter</code> property of our associated
 * <code>ActionMapping</code>.  This can be used to integrate Struts with
 * other business logic components that are implemented as servlets (or JSP
 * pages), but still take advantage of the Struts controller servlet's
 * functionality (such as processing of form beans).</p>
 *
 * <p>To configure the use of this Action in your <code>struts-config.xml</code>
 * file, create an entry like this:</p>
 *
 * <code> &lt;action path="/saveSubscription"
 * type="org.apache.struts.actions.IncludeAction"
 * name="subscriptionForm" scope="request" input="/subscription.jsp"
 * parameter="/path/to/processing/servlet"&gt; </code>
 *
 * <p>which will include the context-relative URI specified by the
 * <code>parameter</code> attribute.</p>
 *
 * @version $Rev: 471754 $ $Date: 2005-11-09 00:11:45 -0500 (Wed, 09 Nov 2005)
 *          $
 */
public class IncludeAction extends BaseAction {
    // ----------------------------------------------------- Instance Variables

    /**
     * Process the specified HTTP request, and create the corresponding HTTP
     * response (or forward to another web component that will create it).
     * Return an <code>ActionForward</code> instance describing where and how
     * control should be forwarded, or <code>null</code> if the response has
     * already been completed.
     *
     * @param mapping  The ActionMapping used to select this instance
     * @param form     The optional ActionForm bean for this request (if any)
     * @param request  The HTTP request we are processing
     * @param response The HTTP response we are creating
     * @return The forward to which control should be transferred, or
     *         <code>null</code> if the response has been completed.
     * @throws Exception if an error occurs
     */
    public ActionForward execute(ActionMapping mapping, ActionForm form,
        HttpServletRequest request, HttpServletResponse response)
        throws Exception {
        // Create a RequestDispatcher the corresponding resource
        String path = mapping.getParameter();

        if (path == null) {
            throw new ServletException(messages.getMessage("include.path"));
        }

        RequestDispatcher rd =
            servlet.getServletContext().getRequestDispatcher(path);

        if (rd == null) {
            throw new ServletException(messages.getMessage("include.rd", path));
        }

        // Forward control to the specified resource
        rd.include(request, response);

        // Tell the controller servlet that the response has been created
        return (null);
    }
}
